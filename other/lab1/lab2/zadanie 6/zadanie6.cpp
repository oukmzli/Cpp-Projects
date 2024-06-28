#include <iostream>

int main () {
    const int l = 10;
    int a[l][l], b[l][l];

    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < l; ++j) {
            a[i][j] = j;
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "+\n";

    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < l; ++j) {
            b[i][j] = 0;
            std::cout << b[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "=\n";

    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < l; ++j) {
            b[i][j] += a[j][i];
            std::cout << b[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}