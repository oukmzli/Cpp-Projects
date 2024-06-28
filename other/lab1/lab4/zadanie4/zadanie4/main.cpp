#include <iostream>

double* function() {
    return new double(1.5);
}

int main () {
    double* b = function();
    std::cout << "b: " << b << "\nv(b): " <<*b << "\n";
    
    delete b; return 0;
}
