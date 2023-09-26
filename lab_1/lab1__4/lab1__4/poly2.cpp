#include "poly2.h"
#include <cmath>
#include <iostream>
#include <cmath>
#include <fstream>

Poly2::Poly2(float a, float b, float c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

float Poly2::eval(float x)
{
	return a * x * x + b * x + c;
}

void Poly2::findRootsUppgift8() {
	float d = b * b - 4 * a * c;
	if (d < 0) {
		std::cout << "Is imaginary number" << std::endl << std::endl;
		return;
	}
	if (d == 0) {
		float result = -b / (2 * a);
		std::cout << "result: " << result << std::endl;
	}
	if (d > 0) {
		float negativeResult = (-b - sqrt(d)) / (2 * a);
		std::cout << "result-: " << negativeResult << std::endl;
		float positiveResult = (-b + sqrt(d)) / (2 * a);
		std::cout << "result+: " << positiveResult;
	}
	std::cout << std::endl << std::endl;
}

void Poly2::findRootsUppgift9(float& amountRoots, float& positiveValue, float& negativeValue) {
	float d = b * b - 4 * a * c;
	if (d < 0) {
		amountRoots = 0;
	}
	if (d == 0) {
		float result = -b / (2 * a);
		positiveValue = result;
		amountRoots = 1;
	}
	if (d > 0) {
		float positiveResult = (-b + sqrt(d)) / (2 * a);
		positiveValue = positiveResult;
		float negativeResult = (-b - sqrt(d)) / (2 * a);
		negativeValue = negativeResult;
		amountRoots = 2;
	}
}
