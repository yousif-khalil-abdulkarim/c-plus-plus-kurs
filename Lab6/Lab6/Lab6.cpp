// Lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<regex>
#include"Interpreter.h"
using namespace std;

vector<vector<string>> getTokens(string fileName) {
    ifstream inputFileStream = ifstream(fileName);
    regex findTokensRegex = regex("[^\\s]+");
    vector<vector<string>> tokens = vector<vector<string>>();
    if (inputFileStream.is_open()) {
        string line;
        while (getline(inputFileStream, line)) {
            smatch results;
            string::const_iterator startIterator = line.cbegin();
            vector<string> tokenRow = vector<string>();
            while(regex_search(startIterator, line.cend(), results, findTokensRegex)) {
                for (ssub_match subMatch : results) {
                    string token = subMatch.str();
                    tokenRow.push_back(token);
                }
                startIterator = results[0].second;
            }
            tokens.push_back(tokenRow);
        }
        inputFileStream.close();
    }
    return tokens;
}

int main()
{
    ofstream outputFileStream = ofstream("output.txt");
    if (outputFileStream.is_open()) {
        vector<vector<string>> allTokens = getTokens("input.txt");

        Interpreter interpreter = Interpreter(outputFileStream);
        for (vector<string> tokensRow : allTokens) {
            interpreter.evalute(tokensRow);
        }
        outputFileStream.close();
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
