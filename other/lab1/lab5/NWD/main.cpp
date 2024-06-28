#include <iostream>

unsigned int nwd(int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) a %= b;
        else b %= a;
    }
    return a + b;
}

unsigned int nww (int a, int b) {
    return a*b/nwd(a, b);
}

int main() {
    int a, b; std::cin >> a >> b;
    std::cout << "NWD to: " << nwd(a, b) << std::endl;
    std::cout << "NWW to: " << nww(a, b) << std::endl;
    
    
    
    return 0;
}
