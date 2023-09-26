#include<vector>
#include "String.h"

size_t strlen(const char* str) {
	size_t size = 0;
	while (*str != '\0') {
		size++;
		str++;
	}
	return size;
};
size_t calcCapacity(size_t size, size_t growSize) {
	if (size < growSize) {
		return growSize;
	}
	return ((size + growSize - 1) / growSize * growSize) + 1;
};
void String::extendCapacityIfNedded(int newCapacity) {
	if (this->_capacity < newCapacity) {
		char* newChars = new char[newCapacity]();
		for (int i = 0; i < this->_size; i++) {
			newChars[i] = this->chars[i];
		}
		newChars[this->_size] = '\0';
		delete[] this->chars;
		this->chars = newChars;
		this->_capacity = newCapacity;
	}
}
String::~String() {
	delete[] this->chars;
};
String::String() {
	this->_size = 0;
	this->_capacity = calcCapacity(0, this->growSize);
	this->chars = new char[this->_capacity]();
	this->chars[0] = '\0';
};
String::String(const String& rhs) {
	this->_size = rhs.size();
	this->_capacity = rhs._capacity;
	this->chars = new char[this->_capacity]();
	for (int i = 0; i < this->_size; i++) {
		this->chars[i] = rhs[i];
	}
	this->chars[this->_size] = '\0';
};
String::String(const char* cstr) {
	this->_size = strlen(cstr);
	this->_capacity = calcCapacity(this->_size, this->growSize);
	this->chars = new char[this->_capacity]();
	for (int i = 0; i < this->_size; i++) {
		this->chars[i] = cstr[i];
	}
	this->chars[this->_size] = '\0';
};
String& String::operator=(const String& rhs) {
	if (this == &rhs) {
		return *this;
	}
	if (this->capacity() < rhs.size()) {
		delete[] this->chars;
		this->_capacity = rhs._capacity;
		this->chars = new char[this->_capacity]();
	}
	this->_size = rhs._size;
	for (int i = 0; i < this->_size; i++) {
		this->chars[i] = rhs[i];
	}
	this->chars[this->_size] = '\0';
	return *this;
};
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
	return this->_capacity - 1;
};
void String::push_back(char c) {
	int newSize = this->_size + 1;
	int newCapacity = calcCapacity(newSize, this->growSize);
	this->extendCapacityIfNedded(newCapacity);
	this->chars[this->_size] = c;
	this->chars[this->_size + 1] = '\0';
	this->_size = newSize;
};
const char* String::data() const {
	/*
	char* testChars = new char[this->_size]();
	for (int i = 0; i < this->_size; i++) {
		testChars[i] = this->chars[i];
	}
	return testChars;
	*/
	return this->chars;
};


bool operator==(const String& lhs, const String& rhs) {
	if (lhs._size != rhs._size) {
		return false;
	}
	bool isMatching = true;
	for (int i = 0; i < lhs._size; i++) {
		isMatching = isMatching && lhs[i] == rhs[i];
		if (!isMatching) {
			return false;
		}
	}
	return true;
}
bool operator!=(const String& lhs, const String& rhs) {
	return !(lhs == rhs);
}
std::ostream& operator<<(std::ostream& out, const String& rhs) {
	out << rhs.chars;
	return out;
}
