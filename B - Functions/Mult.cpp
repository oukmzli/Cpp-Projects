#include <string>
#include <cstdarg>
using namespace std;

void multListToArray(int count, int i, string str[], va_list args) {
    if (i < count) {
        str[i] = va_arg(args, char*);
        multListToArray(count, i+1, str, args);
    }
}

string multRemoveLeadingZeros(const string& num, size_t index) {
    if (index >= num.length() || num[index] != '0') {
        if (index == num.length()) return "0";
        return num.substr(index);
    }
    return multRemoveLeadingZeros(num, index + 1);
}

string multAddStrings(const string& a, const string& b, long long i, long long j, int carry) {
    if (i < 0 && j < 0 && carry == 0) return "";
    int sum = carry + (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0);
    char nextDigit = (sum % 10) + '0';
    return multAddStrings(a, b, i - 1, j - 1, sum / 10) + nextDigit;
}

string multRemoveSign(const string& num) {
    if (!num.empty() && (num[0] == '+' || num[0] == '-')) return num.substr(1);
    return num;
}

bool multIsNegative(const string& num) {
    return !num.empty() && num[0] == '-';
}


string multDigit(const string& num, char digit, long long shift, size_t index = 0, int carry = 0) {
    if (index >= num.length() && carry == 0) {
        return shift > 0 ? string(shift, '0') : "";
    }
    
    int n = index < num.length() ? num[num.length() - 1 - index] - '0' : 0;
    int d = digit - '0';
    int product = n * d + carry;
    char nextDigit = '0' + (product % 10);
    
    return multDigit(num, digit, shift, index + 1, product / 10) + nextDigit;
}

string multStringsHelper(const string& a, const string& b, size_t index, string& result) {
    if (index == b.length()) {
        return multRemoveLeadingZeros(result, 0);
    }
    
    string temp = multDigit(a, b[b.length() - 1 - index], 0) + string(index, '0');
    result = multAddStrings(result, temp, result.length() - 1, temp.length() - 1, 0);
    
    return multStringsHelper(a, b, index + 1, result);
}

string multStrings(const string& a, const string& b) {
    string aTemp = multRemoveSign(a), bTemp = multRemoveSign(b);
    bool negative = multIsNegative(a) ^ multIsNegative(b);
    
    string result = "0";
    result = multStringsHelper(aTemp, bTemp, 0, result);
    result == "0" ? negative = false : negative;
    return negative ? "-" + result : result;
}

string Mult(int count, const string* strArray) {
    if (count <= 0) return "1";
    return multStrings(Mult(count-1, strArray), strArray[count-1]);
}

string Mult(int count, ...) {
    va_list args;
    va_start(args, count);
    string* strArray = new string[count];
    multListToArray(count, 0, strArray, args);
    va_end(args);
    string result = Mult(count, strArray);
    delete [] strArray; return result;
}

void Mult(string* result, int count, const string* strArray) {
    *result = Mult(count, strArray);
}

void Mult(string* result, int count, ...) {
    va_list args;
    va_start(args, count);
    string* strArray = new string[count];
    multListToArray(count, 0, strArray, args);
    va_end(args);
    Mult(result, count, strArray);
    delete [] strArray;
}

void Mult(string& result, int count, const string* strArray) {
    result = Mult(count, strArray);
}

void Mult(string& result, int count, ...) {
    va_list args;
    va_start(args, count);
    string* strArray = new string[count];
    multListToArray(count, 0, strArray, args);
    va_end(args);
    Mult(result, count, strArray);
    delete [] strArray;
}
