#ifndef Sum_h
#define Sum_h

#include <string>
#include <cstdarg>
#include <iostream>
using namespace std;

string Sum(int count, const string* strArray);
string Sum(int count, ...);
void Sum(string* result, int count, const string* strArray);
void Sum(string* result, int count, ...);
void Sum(string& result, int count, const string* strArray);
void Sum(string& result, int count, ...);

#endif
