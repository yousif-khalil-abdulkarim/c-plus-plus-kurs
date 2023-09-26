// Lab1__3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<fstream>
#include<istream>
#include<string>
#include<vector>

void uppgift4() {
	int value;
	int sum = 0;
	std::cout << "enter numbers: " << std::endl;
	while (std::cin >> value) {
		sum += value;
	}
	std::cout << "sum: " << sum;
}

void uppgift5() {
	int value;
	int sum = 0;
	std::cout << "enter numbers: " << std::endl;
	while (std::cin >> value) {
		sum += value;
	}
	std::cout << "sum: " << sum;
	std::ofstream outputFile = std::ofstream("sum.txt");
	if (outputFile.is_open()) {
		outputFile << sum;
	}
	outputFile.close();
}

void uppgift6() {
	std::ifstream inputFile = std::ifstream("terms.txt");
	std::vector<int> numbers = std::vector<int>();
	if (inputFile.is_open()) {
		std::string line;
		int i = 0;
		while (std::getline(inputFile, line))
		{
			std::cout << "number " << (i + 1) << ": " << line << std::endl;
			numbers.push_back(stoi(line));
			i++;
		}
		inputFile.close();
	}
	int sum = 0;
	for (int i = 0; i < numbers.size(); i++) {
		int number = numbers.at(i);
		sum += number;
	}
	std::cout << "sum: " << sum;
}

void uppgift7() {
	std::ifstream inputFile = std::ifstream("terms.txt");
	std::vector<int> numbers = std::vector<int>();
	if (inputFile.is_open()) {
		std::string line;
		int i = 0;
		while (std::getline(inputFile, line))
		{
			std::cout << "number " << (i + 1) << ": " << line << std::endl;
			numbers.push_back(stoi(line));
			i++;
		}
		inputFile.close();
	}
	int sum = 0;
	for (int i = 0; i < numbers.size(); i++) {
		int number = numbers.at(i);
		sum += number;
	}
	std::cout << "sum: " << sum;
	std::ofstream outputFile = std::ofstream("sum.txt");
	if (outputFile.is_open()) {
		outputFile << sum;
	}
	outputFile.close();
}

int main()
{
    // uppgift4();
    // uppgift5();
    // uppgift6();
    // uppgift7();
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
