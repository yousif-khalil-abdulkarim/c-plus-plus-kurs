#include "String.h"
#include<vector>

const int String::growSize = 16;
int String::calcCapacity(int size, int growSize) {
	if (size < growSize) {
		return growSize;
	}
	int chunks = size / growSize;
	int rest = size - chunks * growSize;
	if (rest > 0) {
		chunks++;
	}
	return (chunks * growSize) + 1;
};
int String::cstrLength(const char* cstr) {
	const char* indexPointer = cstr;
	int size = 0;
	while(*indexPointer != '\0') {
		size++;
		indexPointer++;
	}
	return size;
};
void grow() {}
String::~String() {
	delete[] this->chars;
};
String::String() {
	const int capacity = String::calcCapacity(String::growSize, String::growSize);
	this->_capacity = capacity;
	this->chars = new char[capacity]();
	this->chars[0] = '\0';
	this->_size = 0;
};
String::String(const String& rhs) {
	const int size = rhs.size();
	const int capacity = String::calcCapacity(size, String::growSize);
	this->chars = new char[capacity]();
	this->_capacity = capacity;
	for (int i = 0; i < size; i++) {
		this->chars[i] = rhs[i];
	}
	this->chars[size] = '\0';
	this->_size = size;
};
String::String(const char* cstr) {
	const int size = String::cstrLength(cstr);
	const int capacity = String::calcCapacity(size, String::growSize);
	this->chars = new char[capacity]();
	this->_capacity = capacity;
	for (int i = 0; i < size; i++) {
		this->chars[i] = cstr[i];
	}
	this->chars[size] = '\0';
	this->_size = size;
};
String& String::operator=(const String& rhs) {};
char& String::operator[](size_t i) {
	return this->chars[i];
};
const char& String::operator[](size_t i) const {
	return this->chars[i];
};
size_t String::size() const {
	return this->_size;
};
size_t String::capacity() const {
	return this->_capacity;
};
void String::push_back(char c) {
	const int newSize = this->_size + 1;
	const int newCapacity = String::calcCapacity(newSize, String::growSize);
	if (newCapacity != this->_capacity) {
		char* newChars = new char[newCapacity]();
		for (int i = 0; i < this->_size; i++) {
			newChars[i] = this->chars[i];
		}
		newChars[this->_size] = '\0';
		delete[] this->chars;
		this->chars = newChars;
	}
	this->chars[newSize - 1] = c;
	this->chars[newSize] = '\0';
};
const char* String::data() const {
	const int size = this->_size;
	char* chars = new char[size]();
	for (int i = 0; i < size; i++) {
		chars[i] = this->chars[i];
	}
	return chars;
};