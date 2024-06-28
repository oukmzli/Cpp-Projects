#include <iostream>

int main () {
    const int l = 10;
    int a[l][l];

    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < l; ++j) {
            i == (l-j-1) ? a[i][j] = 1 : a[i][j] = 0;
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}