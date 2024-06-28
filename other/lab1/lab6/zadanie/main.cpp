// Denys Kyrychenko
#include <iostream>

int main() {
    int blob[13]; blob[0] = 1;
    for (int i = 0; i < 13; ++i)
        if (i > 1) blob[i] = blob[i - 1] + blob [i - 2];
    std::cout << "waga bloba po trzynastym okrazeniu to " << blob[12] << "kg.\n";
    return 0;
}
