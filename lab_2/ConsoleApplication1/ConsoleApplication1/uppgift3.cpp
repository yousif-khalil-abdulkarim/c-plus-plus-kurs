#include "uppgift3.h"

int getLength(const char* input) {
	int size = 0;
	while (*input != '\0') {
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

char* getNewInitialCStr(const char* input, const char before, const char* after) {
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
	char* newCStr2 = newCStr;
	int initiaNewCStrSize = getLength(newCStr);
	while (*input != '\0') {
		int isMatching = *input == before;
		if (isMatching) {
			for (int i = 0; i < getLength(after); i++) {
				char chr = after[i];
				*newCStr = chr;
				newCStr++;
			}
		}
		else {
			*newCStr = *input;
			newCStr++;
		}
		input++;
	}
	newCStr -= initiaNewCStrSize;
	return newCStr;
}
