#include <iostream>

 //zadanie 1:
int smaller(int* a, int* b) {
    return *a < *b ? *a : *b;
}

 //zadanie 2:
int *smallerPointer(int* a, int* b) {
    return *a < *b ? a : b;
}
 //zadanie 3:
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

 //zadanie 4:
void swapRef(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

 //zadanie 5:
int *reserve() {
    return new int;
}

 //zadanie 6:
int *block(unsigned int n) {
    return new int[n];
}

 //zadanie 7: sho...? FUNKCJONAL

 //zadanie 8:
void constToInt(const int *a, int *b) {
    *b = *  a;
}

int main() {
    int a = 5, b = 4;
    std::cout << "a:" << &a << "\tb:" << &b << "\n";
    std::cout << "zadanie1: " << smaller(&a, &b) << std::endl;
    std::cout << "zadanie2: " << smallerPointer(&a, &b) << std::endl;
    
    swap(&a, &b);
    std::cout << "zadanie3: swap(&a, &b) - " << "a: " << a << " b: " << b << std::endl;
    swapRef(a, b);
    std::cout << "zadanie4: swapRef(a, b) - " << "a: " << a << " b: " << b << std::endl;

    return 0;
}


