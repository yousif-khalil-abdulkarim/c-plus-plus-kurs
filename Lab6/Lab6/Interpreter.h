#ifndef INTERPRETER
#define INTERPRETER
#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

static const string ETX = "\u0003";
static bool isInt(string token);
static bool isVariable(string token);
static bool isValidConfigValue(string value);

class InterpreterContext {
	string config = "";
	unordered_map<string, int> variables = unordered_map<string, int>();
public:
	void setConfig(const string const& value);
	const string const* getConfig();
	void setVariable(const string const& name, int value);
	const int const* getVariable(const string const& name);
};

class InterpretLine {
	ostream* outStream = nullptr;
	InterpreterContext* context;
	int position = 0;
	const vector<string> const* tokens;
	string peek(int steps = 0);
	void consume(string token);
	int parsePrimaryExpression();
	int parseProductExpression();
	int parseSumExpression();
	int parseMathExpression();
	void parsePrintStatement();
	void parseConfigStatement();
	void parseAssignmentStatement();
	void parseStatement();
public:
	InterpretLine(const vector<string>& tokens, InterpreterContext& context, ostream* outStream);
	void run();
};

class Interpreter {
	InterpreterContext context = InterpreterContext();
	ostream* outStream = nullptr;
public:
	Interpreter(ostream& outStream);
	void evalute(const vector<string>& tokens);
};
#endif