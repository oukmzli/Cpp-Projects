// Denys Kyrychenko
#include <iostream>
#include <string>

bool isPalindrome(const std::string& str) {
    unsigned long n = str.size();
    for (int i = 0; i < n / 2; ++i)
        if (str[i] != str[n - i - 1])
            return false;
    
    return true;
}

int main() {
    std::string testStr = "kajak";
    std::cout << (isPalindrome(testStr) ? "True" : "False") << std::endl;

    return 0;
}
