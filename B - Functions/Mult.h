#ifndef Mult_h
#define Mult_h

#include <string>
#include <cstdarg>
#include <iostream>
using namespace std;

string Mult(int count, const string* strArray);
string Mult(int count, ...);
void Mult(string* result, int count, const string* strArray);
void Mult(string* result, int count, ...);
void Mult(string& result, int count, const string* strArray);
void Mult(string& result, int count, ...);

#endif
