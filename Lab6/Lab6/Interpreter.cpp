#include "Interpreter.h"
#include<string>
#include<vector>
#include<iostream>
#include<regex>
#include<bitset> 
using namespace std;

static bool isInt(string token) {
	regex intRegex{ "^(-?[0-9]+)$" };
	return regex_match(token, intRegex);
}
static bool isVariable(string token) {
	regex variableRegex{ "^([a-zA-Z][a-zA-Z0-9]*)$" };
	return regex_match(token, variableRegex);
}
static bool isValidConfigValue(string value) {
	return value == "dec" || value == "bin" || value == "hex";
}

void InterpreterContext::setConfig(const string& value) {
	this->config = value;
}
const const string const* InterpreterContext::getConfig() {
	return &this->config;
}
void InterpreterContext::setVariable(const string const& name, int value) {
	this->variables[name] = value;
}
const int const* InterpreterContext::getVariable(const string const& name) {
	int* value = nullptr;
	try {
		value = &this->variables.at(name);
	}
	catch (...) {}
	return value;
}

string InterpretLine::peek(int steps) {
	int index = this->position + steps;
	if (index >= this->tokens->size()) {
		return ETX;
	}
	return (*this->tokens)[index];
}
void InterpretLine::consume(string token) {
	string nextToken = this->peek();
	if (nextToken == ETX) {
		throw exception("Consumed past last token\n");
	}
	if (nextToken != token) {
		string message = "Could not consume token " + token + "\n";
		throw exception(message.c_str());
	}
	this->position++;
};
int InterpretLine::parsePrimaryExpression() {
	int value;
	string nextToken = this->peek();
	if (isInt(nextToken)) {
		this->consume(nextToken);
		value = stoi(nextToken);
	}
	else if (isVariable(nextToken)) {
		const int* variableValue = this->context->getVariable(nextToken);
		this->consume(nextToken);
		if (variableValue == nullptr) {
			string message = "Variable is undeclared: " + nextToken + "\n";
			throw exception(message.c_str());
		}
		value = *variableValue;
	}
	else if (nextToken == "(") {
		this->consume("(");
		value = this->parseMathExpression();
		if (this->peek() == ")") {
			this->consume(")");
		}
		else {
			throw exception("Expected: )\n");
		}
	}
	else {
		throw exception("Expected: int or ( )\n");
	}
	return value;
};
int InterpretLine::parseProductExpression() {
	int result = this->parsePrimaryExpression();
	string nextToken = this->peek();
	while (true) {
		if (nextToken == "*") {
			this->consume("*");
			result = result * this->parsePrimaryExpression();
		}
		else if (nextToken == "/") {
			this->consume("/");
			result = result / this->parsePrimaryExpression();
		}
		else {
			break;
		}
		nextToken = this->peek();
	}
	return result;
};
int InterpretLine::parseSumExpression() {
	int result = this->parseProductExpression();
	string nextToken = this->peek();
	while (true) {
		if (nextToken == "+") {
			this->consume("+");
			result = result + this->parseProductExpression();
		}
		else if (nextToken == "-") {
			this->consume("-");
			result = result - this->parseProductExpression();
		}
		else {
			break;
		}
		nextToken = this->peek();
	}
	return result;
};
int InterpretLine::parseMathExpression() {
	return this->parseSumExpression();
};
void InterpretLine::parsePrintStatement() {
	string nextToken = this->peek();
	if (nextToken == "print") {
		this->consume("print");
		int value = this->parseMathExpression();
		const string const* configValue = this->context->getConfig();
		if (*configValue == "bin") {
			*this->outStream << bitset<32>(value).to_string() << endl;
		}
		else if (*configValue == "hex") {
			*this->outStream << hex << showbase << value << endl;
		}
		else if (*configValue == "dec") {
			*this->outStream << dec << value << endl;
		}
		else if (*configValue == "") {
			throw exception("Config must be defined");
		}
		else {
			string message = ("Config value is not supported: " + *configValue + "\n");
			throw exception(message.c_str());
		}
	}
};
void InterpretLine::parseConfigStatement() {
	string nextToken = this->peek();
	if (nextToken == "config") {
		this->consume("config");
		nextToken = this->peek();
		if (isValidConfigValue(nextToken)) {
			this->consume(nextToken);
			this->context->setConfig(nextToken);
		}
		else {
			throw exception("Config value invalid must be: hex, dec, bin");
		}
	}
};
void InterpretLine::parseAssignmentStatement() {
	string nextToken = this->peek();
	string nextNextToken = this->peek(1);
	if (isVariable(nextToken) && nextNextToken == "=") {
		this->consume(nextToken);
		this->consume(nextNextToken);
		int value = this->parseMathExpression();
		this->context->setVariable(nextToken, value);
	}
};
void InterpretLine::parseStatement() {
	this->parseConfigStatement();
	this->parseAssignmentStatement();
	this->parsePrintStatement();
}
void InterpretLine::run() {
	this->parseStatement();
}
InterpretLine::InterpretLine(const vector<string>& tokens, InterpreterContext& context, ostream* outStream) {
	this->tokens = &tokens;
	this->context = &context;
	this->outStream = outStream;
};

Interpreter::Interpreter(ostream& outStream) {
	this->outStream = &outStream;
};
void Interpreter::evalute(const vector<string>& tokens) {
	InterpretLine interpretLine = InterpretLine(tokens, this->context, this->outStream);
	interpretLine.run();
};
