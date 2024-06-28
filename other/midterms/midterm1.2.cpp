#include <iostream>
#include <string>

void rotateStr(std::string &str) {
    for (int i = 0; i < str.length() / 2; i++) {
        std::swap(str[i], str[str.length() - i - 1]);
    }
}

std::string intToString(int n) {
    std::string str = "";
    
    bool isNegative = (n < 0);
    if (isNegative) n = -n;

    do {
        int digit = n % 10;
        str += '0' + digit;
        n /= 10;
    } while (n > 0);

    if (isNegative) str += '-';
    
    rotateStr(str);
    return str;
}

int main() {
    int test[] = {123, -456, 0, 10000, -99999};
    
    for (int i : test) {
        std::cout << "Int: " << i << ", string: " << intToString(i) << std::endl;
    }

    return 0;
}
