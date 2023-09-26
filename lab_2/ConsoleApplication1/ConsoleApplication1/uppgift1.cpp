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
	int size = n - 1;
	int* nbrs = new int[size]();
	for (int i = 0; i < size; i++) {
		nbrs[i] = 2 + i;
	}

	for (int i = 0; i < size; i++) {
		int nbr = nbrs[i];
		int nbrPowerBy2 = nbr * nbr;
		bool shouldContinue = nbrPowerBy2 <= n;
		if (!shouldContinue) {
			break;
		}
		bool isAlreadyComposite = nbr == -1;
		if (isAlreadyComposite) {
			continue;
		}
		for (int j = i + 1; j < size; j++) {
			int compareNbr = nbrs[j];
			bool isAlreadyComposite = compareNbr == -1;
			if (isAlreadyComposite) {
				continue;
			}
			bool isComposite = (compareNbr % nbr) == 0;
			if (isComposite) {
				nbrs[j] = -1;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		int nbr = nbrs[i];
		if (nbr != -1) {
			std::cout << nbr << std::endl;
		}
	}

	delete[] nbrs;
}
