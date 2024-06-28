#include <string>
#include <cstdarg>
using namespace std;

void SumListToArray(int count, int i, string str[], va_list args) {
    if (i < count) {
        str[i] = va_arg(args, char*);
        SumListToArray(count, i+1, str, args);
    }
}

string removeLeadingZeros(const string& num, size_t index) {
    if (index >= num.length() || num[index] != '0') {
        if (index == num.length()) return "0";
        return num.substr(index);
    }
    return removeLeadingZeros(num, index + 1);
}

int compare(const string& a, const string& b, size_t index) {
    if (index == a.length()) return 0;
    if (a[index] < b[index]) return -1;
    if (a[index] > b[index]) return 1;
    return compare(a, b, index + 1);
}

int compareStrings(const string& a, const string& b) {
    string aTemp = removeLeadingZeros(a, 0);
    string bTemp = removeLeadingZeros(b, 0);
    
    if (aTemp.length() != bTemp.length()) {
        return aTemp.length() > bTemp.length() ? 1 : -1;
    }
    
    return compare(aTemp, bTemp, 0);
}

bool isNegative(const string& num) {
    return !num.empty() && num[0] == '-';
}

string removeSign(const string& num) {
    if (!num.empty() && (num[0] == '+' || num[0] == '-')) return num.substr(1);
    return num;
}

string subtractStrings(const string& a, const string& b, long long i, long long j, int borrow) {
    if (i < 0 && j < 0 && borrow == 0) return "";
    int diff = (i >= 0 ? a[i] - '0' : 0) - (j >= 0 ? b[j] - '0' : 0) - borrow;
    if (diff < 0) { diff += 10; borrow = 1; } else borrow = 0;
    char nextDigit = '0' + (diff % 10);
    string result = subtractStrings(a, b, i - 1, j - 1, borrow);
    return result + nextDigit;
}

string addStrings(const string& a, const string& b, long long i, long long j, int carry) {
    if (i < 0 && j < 0 && carry == 0) return "";
    int sum = carry + (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0);
    char nextDigit = (sum % 10) + '0';
    return addStrings(a, b, i - 1, j - 1, sum / 10) + nextDigit;
}

string sumStrings(const string& a, const string& b) {
    bool bothNegative = isNegative(a) && isNegative(b);
    string aTemp = removeSign(a);
    string bTemp = removeSign(b);
    string result;
    
    if ((isNegative(a) && isNegative(b)) || (!isNegative(a) && !isNegative(b))) {
        result = addStrings(aTemp, bTemp, aTemp.length() - 1, bTemp.length() - 1, 0);
        if (bothNegative) result = "-" + removeLeadingZeros(result, 0);
        
    } else if (isNegative(a)) {
        int comparison = compareStrings(aTemp, bTemp);
        if (comparison == 1) {
            result = subtractStrings(aTemp, bTemp, aTemp.length() - 1, bTemp.length() - 1, 0);
            result = "-" + removeLeadingZeros(result, 0);
        } else if (comparison == -1) {
            result = subtractStrings(bTemp, aTemp, bTemp.length() - 1, aTemp.length() - 1, 0);
        }
    } else if (isNegative(b)) {
        int comparison = compareStrings(bTemp, aTemp);
        if (comparison == 1) {
            result = subtractStrings(bTemp, aTemp, bTemp.length() - 1, aTemp.length() - 1, 0);
            removeLeadingZeros(result, 0);
            result = "-" + removeLeadingZeros(result, 0);
        } else if (comparison == -1) {
            result = subtractStrings(aTemp, bTemp, aTemp.length() - 1, bTemp.length() - 1, 0);
        }
    }
    
    return removeLeadingZeros(result, 0);
}


string Sum(int count, const string* strArray) {
    if (count <= 0) return "0";
    return sumStrings(Sum(count-1, strArray), strArray[count-1]);
}

string Sum(int count, ...) {
    va_list args;
    va_start(args, count);
    string* strArray = new string[count];
    SumListToArray(count, 0, strArray, args);
    va_end(args);
    string result = Sum(count, strArray);
    delete [] strArray; return result;
}

void Sum(string* result, int count, const string* strArray) {
    *result = Sum(count, strArray);
}

void Sum(string* result, int count, ...) {
    va_list args;
    va_start(args, count);
    string* strArray = new string[count];
    SumListToArray(count, 0, strArray, args);
    va_end(args);
    Sum(result, count, strArray);
    delete [] strArray;
}

void Sum(string& result, int count, const string* strArray) {
    result = Sum(count, strArray);
}

void Sum(string& result, int count, ...) {
    va_list args;
    va_start(args, count);
    string* strArray = new string[count];
    SumListToArray(count, 0, strArray, args);
    va_end(args);
    Sum(result, count, strArray);
    delete [] strArray;
}
