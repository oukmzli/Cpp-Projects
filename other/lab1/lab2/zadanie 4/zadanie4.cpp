#include <iostream>

int main() {
    int a[10][10];
    int count = 0;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i == j) a[i][j] = count++;
            else a[i][j] = 0;
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }

    int sum = 0;
    for (int i = 0; i < count; i++)
        for (int j = 0; j < count; j++)
            if (i == j) sum += a[i][j];

    std::cout << "Sum of diagonal is: " << sum << "\n";

    return 0;
}