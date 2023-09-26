// lab1__4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "poly2.h"
#include<iostream>
#include<fstream>
#include<string>
#include<istream>
#include<vector>
#include<fstream>

void uppgift10() {

    std::cout << "input numbers: " << std::endl;
    float value;
    std::vector<float> numbers = {};
    while (std::cin >> value) {
        numbers.push_back(value);
    }
    for (int i = 0; i < numbers.size(); i += 3) {
        float a = numbers[i];
        std::cout << "a: " << a << ", ";
        float b = numbers[i + 1];
        std::cout << "b: " << b << ", ";
        float c = numbers[i + 2];
        std::cout << "c: " << c << std::endl;
        Poly2 poly2 = Poly2(a, b, c); 
        float amountRoots = 0; 
        float positiveValue = 0; 
        float negativeValue = 0;
        poly2.findRootsUppgift9(amountRoots, positiveValue, negativeValue);
        std::cout << "root amount: " << amountRoots << std::endl;
        std::cout << "postive result: " << positiveValue << std::endl;
        std::cout << "negative result: " << negativeValue << std::endl;
        std::cout << std::endl;
    }
}

void uppgift11() {
    std::vector<std::string> numbers = {};

    std::ifstream inputFile = std::ifstream("coeffs.txt");
    if (!inputFile.is_open()) {
        return;
    }
    std::string line;
    while (getline(inputFile, line, ' ')) {
        numbers.push_back(line);
    }
    inputFile.close();

    std::ofstream fileOutput = std::ofstream("roots.txt");
    if (!fileOutput.is_open()) {
        return;
    }
    for (int i = 0; i < numbers.size(); i += 3) {
        float a = stof(numbers[i]);
        std::cout << "a: " << a << ", ";
        float b = stof(numbers[i + 1]);
        std::cout << "b: " << b << ", ";
        float c = stof(numbers[i + 2]);
        std::cout << "c: " << c << std::endl;
        Poly2 poly2 = Poly2(a, b, c);
        float amountRoots = 0; float positiveValue = 0; float negativeValue = 0;
        poly2.findRootsUppgift9(amountRoots, positiveValue, negativeValue);
        std::cout << "root amount: " << amountRoots << std::endl;
        std::cout << "postive result: " << positiveValue << std::endl;
        std::cout << "negative result: " << negativeValue << std::endl;
        std::cout << std::endl;
        fileOutput << amountRoots << " " << positiveValue << " " << negativeValue << std::endl;
    }
    fileOutput.close();
}

int main()
{
    // uppgift10();
    uppgift11();
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
