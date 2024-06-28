// Denys Kyrychenko
#include <iostream>
using namespace std;

struct student {
    string name;
    short subjects[4];
    string subjectNames[4] = {"Algebry","Programowania","Architektury komputerow","Wstepu do Informatyki"};
};

int main() {
    student student[5];
    
    for (int i = 0; i < 5; ++i) {
        cout << "Podaj imie studenta nr" << i+1 << ": "; cin >> student[i].name;
        cout << "Podaj ocene z Algebry: "; cin >> student[i].subjects[0];
        cout << "Podaj ocene z Programowania: "; cin >> student[i].subjects[1];
        cout << "Podaj ocene z Architektury komputerow: "; cin >> student[i].subjects[2];
        cout << "Podaj ocene z Wstepu do Informatyki: "; cin >> student[i].subjects[3];
    }
    
    int zapytania, studentNum, subjectNum;
    cout << "Podaj liczbe zapytan: "; cin >> zapytania;
    while (zapytania--) {
        cout << "Podaj nr studenta z przedzialu [1..5]: "; cin >> studentNum;
        cout << "Podaj nr przedmiotu z przedzialu [0..3]: "; cin >> subjectNum;
        cout << "Student: " << student[studentNum].name << ", ocena z " << student[studentNum].subjectNames[subjectNum] << ": " << student[studentNum].subjects[subjectNum];
    }
    
    return 0;
}
