#include <iostream>

int main() {
    int x = 20;
    int *a = &x;
    
    std::cout << "\n\t*a: " << *a << "\t\t\t\t\t x: " << x << "\n\t&a: " << &a << "\t\t&x: " << &x << "\n\n";
    
    return 0;
}
