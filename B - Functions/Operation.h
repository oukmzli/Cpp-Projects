#ifndef Operation_h
#define Operation_h

#include <string>
#include <cstdarg>
using namespace std;

string Operation(string (*func)(int, const string*), int count, const string* args);
string Operation(string (*func)(int, const string*), int count, ...);
void Operation(string* result, string (*func)(int, const string*), int count, const string* strArray);
void Operation(string* result, string (*func)(int, const string*), int count, ...);
void Operation(string& result, void (*func)(string*, int, const string*), int count, const string* strArray);
void Operation(string& result, void (*func)(string*, int, const string*), int count, ...);

#endif
