// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Uppgift 1
int gcd(int nbrA, int nbrB)
{
	if (nbrA == 0) {
		return nbrB;
	}
	return gcd(nbrB % nbrA, nbrA);
}

bool isPrimeNbr(int* primesArray, int* primesArraySize, int nbrToCheck) {
	int size = *primesArraySize;
	bool isNotPrime = true;
	for (int i = 0; i < size; i++) {
		int prime = primesArray[i];
		int result = gcd(prime, nbrToCheck);
		isNotPrime = isNotPrime && result != 1;
		if (isNotPrime) {
			return false;
		}
	};

	int newSize = size + 1;
	int nextIndex = size;

	primesArray[nextIndex] = nbrToCheck;
	*primesArraySize = newSize;
	return true;
}

void printPrimeNbrs(int n) {
	int size = n - 2;
	int* nbrs = new int[size] {};
	for (int i = 0; i < size; i++) {
		nbrs[i] = i + 2;
	}
	
	int* primes = new int[size];
	for (int i = 0; i < size; i++) {
		primes[i] = -1;
	}
	primes[0] = 2;
	int primesSize = 1;
	

	for (int i = 0; i < size; i++) {
		int nbr = nbrs[i];
		if (nbr == 2) {
			std::cout << "prime: " << nbr << std::endl;
			continue;
		}
		if (isPrimeNbr(primes, &primesSize, nbr)) {
			std::cout << "prime: " << nbr << std::endl;
		}
	}
	delete[] nbrs;
	delete[] primes;
}

// Uppgift 2
void substitute_str(
	std::string& iostring,
	const std::string& before,
	const std::string& after
) {
	int i = 0;
	while (true) {
		int start = iostring.find(before, i);
		if (start == -1) {
			break;
		}
		iostring.replace(start, before.length(), after);
		i = start + after.length();
	}
}

// Uppgift 3
int getLength(const char* input) {
	int size = 0;

	while(*input != '\0') {
		size++;
		input++;
	}
	return size;
}

int charOccurences(const char* input, const char before) {
	int occurences = 0;
	for (int i = 0; i < getLength(input); i++) {
		char letter = input[i];
		if (letter == before) {
			occurences++;
		}
 	}
	return occurences;
}

int getNewLength(const char* input, const char before, const char* after) {
	int occurences = charOccurences(input, before);
	int afterLength = getLength(after);
	int inputLength = getLength(input);
	return occurences * afterLength - occurences + inputLength;
}

char* getNewInitialCStr(const char* input, const char before, const char* after)   {
	int newLength = getNewLength(input, before, after);
	char* newCStr = new char[newLength] {};
	for (int i = 0; i < newLength; i++) {
		newCStr[i] = ' ';
	}
	newCStr[newLength] = '\0';
	return newCStr;
}

char* substitute_cstr(const char* input, const char before, const char* after) {
	char* newCStr = getNewInitialCStr(input, before, after);
	while (*input != '\0') {
		int isMatching = *input == before;
		if (isMatching) {

		}
		input++;
	}
	return newCStr;
}

int main()
{
	const char* input = "ab ab bb";
	const char toReplace = 'b';
	const char* replacement = "cc";
	substitute_cstr(input, toReplace, replacement);
}
