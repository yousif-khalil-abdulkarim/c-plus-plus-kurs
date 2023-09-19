#include <string>
#ifndef UPPGIFT_3
#define UPPGIFT_3
int getLength(const char* input);

int charOccurences(const char* input, const char before);

int getNewLength(const char* input, const char before, const char* after);

char* getNewInitialCStr(const char* input, const char before, const char* after);

char* substitute_cstr(const char* input, const char before, const char* after);
#endif