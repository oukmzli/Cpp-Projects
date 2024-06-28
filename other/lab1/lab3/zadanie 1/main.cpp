/*
sizeof i operatory adresu sa unarne, tak ze maja taki
 sam priorytet, ale np. w sizeof(*p) sizeof oblicza
 rozmiar typu danych, na ktore wskazuje 'p'.
 */

#include <iostream>

int main() {
    char l = 'A'; int n = 2, i = 0;
    for (int j = 0; j < 26; ++j) {
        if (j == 8) {
            std::cout << "\npo ile liter w rzędzie program ma wypisywać dalej? : ";
            std::cin >> n;
            i = 0;
        }
        if (i % n == 0 && i != 0) std::cout << "\n";
        ++i;
        if (l < 'A' + 26) std::cout << l++ << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
