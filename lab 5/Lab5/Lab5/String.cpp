#include "String.h"
#include<vector>

int String::calcCapacity(int size, int growSize) {
	if (size < growSize) {
		return growSize;
	}
	int chunks = size / growSize;
	int rest = size - chunks * this->growSize;
	if (rest > 0) {
		chunks++;
	}
	return (chunks * this->growSize) + 1;
};
String::~String() {
	delete[] this->chars;
};
String::String() {
	this->growSize = 16;
	this->_capacity = this->calcCapacity(0);
	this->_size = 0;
};
String::String(const String& rhs) {
	this->growSize = 16;
	const int size = rhs.size();
	this->_capacity = this->calcCapacity(size);
	this->_size = size;
};
String::String(const char* cstr) {
	this->growSize = 16;
};
String& String::operator=(const String& rhs) {};
char& String::operator[](size_t i) {};
const char& String::operator[](size_t i) const {};
size_t String::size() const {};
size_t String::capacity() const {};
void String::push_back(char c) {};
const char* String::data() const {};