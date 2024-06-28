// Denys Kyrychenko
#include <iostream>

double function(int a, int b) {
    double bDouble = b;
    if (b % 10 == 0) bDouble = 0.1;
    else while (b % 10 != 0) { bDouble /= 10; b /= 10; }
    
    if ((a > 0 && bDouble > 0) || (a < 0 && bDouble < 0)) return a + bDouble;
    else if (a < 0 && bDouble > 0) return a - bDouble;
    else if (a > 0 && bDouble < 0) return a + -1*bDouble;
    else return 0;
}

int main() {
    int a, b; std::cin >> a >> b;
    std::cout << "double: " << function(a, b) << "\n";
    return 0;
}
