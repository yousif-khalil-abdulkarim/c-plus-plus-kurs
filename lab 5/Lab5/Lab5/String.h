#ifndef MY_STRING
#define MY_STRING
#include<iostream>
#include<vector>

class String {
	char* chars;
	int _size;
	int _capacity;
	static const int growSize;
	static int calcCapacity(int size, int growSize);
	static int cstrLength(const char* cstr);
public:
	~String();
	String();
	String(const String& rhs);
	String(const char* cstr);
	String& operator=(const String& rhs);
	char& operator[](size_t i);
	const char& operator[](size_t i) const;
	size_t size() const;
	size_t capacity() const;
	void push_back(char c);
	const char* data() const;
};
#endif