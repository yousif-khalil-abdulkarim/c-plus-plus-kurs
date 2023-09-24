// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "uppgift1.h"
#include "uppgift2.h"
#include "uppgift3.h"

void uppgift1Test() {
	std::cout << "Uppgift 1" << "\n" << std::endl;
	printPrimeNbrs(25);
	std::cout << "\n" << std::endl;
}

void uppgift2Test() {
	std::cout << "Uppgift 2" << "\n" << std::endl;
	std::string input = "Hej po dejje ej";
	std::string toReplace = "ej";
	std::string replacement = "ig";
	substitute_str(input, toReplace, replacement);
	std::cout << "result: " << input << std::endl;
	std::cout << "\n" << std::endl;
}

void uppgift3Test() {
	std::cout << "Uppgift 3" << "\n" << std::endl;
	char* result = substitute_cstr("aabaa", 'a', " cac ");
	std::cout << "result: " << result << std::endl;
	std::cout << "\n" << std::endl;
}

int main()
{
	uppgift1Test();
	uppgift2Test();
	uppgift3Test();
}

