#include <string>
#include <cstdarg>
using namespace std;

void OperationListToArray(int count, int i, string str[], va_list args) {
    if (i < count) {
        str[i] = va_arg(args, char*);
        OperationListToArray(count, i+1, str, args);
    }
}

string Operation(string (*func)(int, const string*), int count, const string* args) {
    return func(count, args);
}

string Operation(string (*func)(int, const string*), int count, ...) {
    string* strArray = new string[count];
    va_list args;
    va_start(args, count);
    OperationListToArray(count, 0, strArray, args);
    string result = func(count, strArray);
    va_end(args); delete [] strArray;
    return result;
}

void Operation(string* result, string (*func)(int, const string*), int count, const string* strArray) {
    *result = func(count, strArray);
}

void Operation(string* result, string (*func)(int, const string*), int count, ...) {
    string* strArray = new string[count];
    va_list args;
    va_start(args, count);
    OperationListToArray(count, 0, strArray, args);
    *result = func(count, strArray);
    va_end(args);
}

void Operation(string& result, void (*func)(string*, int, const string*), int count, const string* strArray) {
    func(&result, count, strArray);
}

void Operation(string& result, void (*func)(string*, int, const string*), int count, ...) {
    string* strArray = new string[count];
    va_list args;
    va_start(args, count);
    OperationListToArray(count, 0, strArray, args);
    func(&result, count, strArray);
    va_end(args);
}
