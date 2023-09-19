#include "uppgift1.h"
#include <iostream>

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
