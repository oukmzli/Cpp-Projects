#include <iostream>

bool evenness (unsigned int a) {
    if (a & 1) return false;
    return true;
}

int main() {
    int a; std::cin >> a;
    std::cout << "is 'a' even? : ";
    if (evenness(a)) std::cout << "true\n";
    else std::cout << "false\n";
    
    return 0;
}
