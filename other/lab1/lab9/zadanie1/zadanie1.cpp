// Denys Kyrychenko
#include <iostream>
#include <string>

int countVowels(const std::string& name, const std::string& vowels) {
    int сount = 0;
    for (char ch : name)
        if (vowels.find(tolower(ch)) != std::string::npos)
            ++сount;
    
    return сount;
}


void displayName(std::string& name, int times) {
    if (times > 0) {
        std::cout << name << std::endl;
        displayName(name, times - 1);
    }
}

int main() {
    std::string name = "Denys";
    std::string vowels = "eyuioa";
    
    displayName(name, countVowels(name, vowels));
    
    return 0;
}
