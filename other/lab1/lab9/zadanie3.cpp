#include <iostream>

unsigned int dlugosc(char* c) {
    int counter = 0;
    while (c[counter] != '\0') counter++;
    return counter;
}

unsigned int dlugosc(wchar_t* c) {
    int counter = 0;
    while (c[counter] != L'\0') counter++;
    return counter;
}

void wyczysc(char* c) {
    int lenght = dlugosc(c);
    for (int i = 0; i < lenght; ++i) c[i] = '\0';
}

void wyczysc(wchar_t* c) {
    int lenght = dlugosc(c);
    for (int i = 0; i < lenght; ++i) c[i] = L'\0';
}

bool leksykograficznieWczesniejszy(char* napis1, char* napis2) {
    if (dlugosc(napis1) == dlugosc(napis2)) {
        int i = 0;
        while (napis1[i] != '\0' && napis2[i] != '\0') {
            if (napis1[i] < napis2[i]) {
                return 1;
            } else if (napis1[i] > napis2[i]) {
                return 0;
            }
            i++;
        }
    }
    
    if (dlugosc(napis1) < dlugosc(napis2)) return 1;
    else return 0;
}

void sklej(char* napis1, char* napis2, char* napis3) {
    int i = 0;
    while (napis1[i] != '\0') { napis3[i] = napis1[i]; ++i; }
    
    int j = 0;
    while (napis2[j] != '\0') { napis3[i++] = napis2[j]; ++j; }
    
    napis3[i] = '\0';
}

int main() {
    std::cout << sizeof(char) << std::endl;
    std::cout << sizeof(wchar_t) << std::endl;
    
    char napis1[6] = "Ala m";
    char napis2[8] = "a kota.";
    char napis3[13];
    sklej(napis1, napis2, napis3);
    for (int i = 0; i < 13; ++i) std::cout << napis3[i];
    return 0;
}
