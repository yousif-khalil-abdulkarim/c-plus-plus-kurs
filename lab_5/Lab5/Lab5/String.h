#ifndef MY_STRING
#define MY_STRING
#include<iostream>
#include<vector>

size_t strlen(const char* str);
size_t calcCapacity(size_t size, size_t growSize);
class String {
	char* chars;
	size_t _size;
	size_t _capacity;
	size_t growSize = 32;
	void extendCapacityIfNedded(int capacity);
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
	friend bool operator==(const String& lhs, const String& rhs);
	friend bool operator!=(const String& lhs, const String& rhs) ;
	friend std::ostream& operator<<(std::ostream& out, const String& rhs);
};
bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);
std::ostream& operator<<(std::ostream& out, const String& rhs);
#endif