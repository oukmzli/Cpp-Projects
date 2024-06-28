// Denys Kyrychenko
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Student {
    string lastname;
    double average;
};

bool operator < (const Student& a, const Student& b) {
    int lex = strcmp(a.lastname.c_str(), b.lastname.c_str());
    if (lex != 0) return lex < 0;
    return a.average > b.average;
}

int main() {
    Student students[] = {
        {"Przybyszewski", 4.12},
        {"Kasprowicz", 3.40},
        {"Wyspianski", 5.00},
        {"Kossak", 2.44},
        {"Tetmajer", 3.32},
        {"Lesmian", 4.44},
        {"Staff", 3.00},
        {"Tuwim", 3.00},
        {"Iwaszkiewicz", 2.20},
        {"Tatarkiewicz", 5.00}
    };
    int studentsQuantity = sizeof(students) / sizeof(students[0]);

    cout << "Dane studentow przed sortowaniem:\n";
    for (int i = 0; i < studentsQuantity; ++i)
        cout << "Nazwisko: " << students[i].lastname << ", srednia: " << students[i].average << endl;
    
    
    sort(students, students + studentsQuantity);

    cout << "\nDane studentow po sortowaniu:" << endl;
    for (int i = 0; i < studentsQuantity; ++i)
        cout << "Nazwisko: " << students[i].lastname << ", srednia: " << students[i].average << endl;

    return 0;
}
