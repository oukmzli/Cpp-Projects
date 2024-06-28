// Denys Kyrychenko
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include <fstream>
using namespace std;

struct MLEKO {
    int num;
    string reg;
    string lastname;
    string name;
    string dob;
    int liter;
    double fat;
    string klasa;
    double wyplata;
};

int main() {
    MLEKO mleko[10];
    ifstream file("plik.txt");
    
    if (!file.is_open()) {
        cout << "Unable to open file" << endl;
        return 1;
    }
    
    for (int i = 0; i < 10; ++i)
        file >> mleko[i].num >> mleko[i].reg >> mleko[i].lastname >> mleko[i].name >> mleko[i].dob >> mleko[i].liter >> mleko[i].fat >> mleko[i].klasa;
    
    file.close();
    /*
     mleko[0] = {1, "Bielawa", "Kalisz", "Eugenia", "1972-12-18", 155, 4.1, "I"};
     mleko[1] = {83, "Olszyna", "Gora", "Lucyna", "1971-09-13", 158, 3.7, "II"};
     mleko[2] = {208, "Strzelin", "Hudzik", "Anna", "1977-01-05", 149, 3.7, "E"};
     mleko[3] = {270, "Czernicha", "Las", "Maria", "1976-04-14", 189, 3.8, "P"};
     mleko[4] = {381, "Brodnica", "Janas", "Jan", "1976-10-15", 562, 3.6, "II"};
     mleko[5] = {415, "Koronowo", "Knapik", "Jan", "1973-08-05", 323, 3.8, "E"};
     mleko[6] = {457, "Lipno", "Dynda", "Henryk", "1974-08-22", 266, 3.7, "I"};
     mleko[7] = {515, "Radomin", "Wojna", "Jacek", "1971-09-03", 108, 3.6, "I"};
     mleko[8] = {636, "Pruszcz", "Mika", "Zofia", "1973-07-13", 125, 3.8, "I"};
     
     mleko[9].num = 828;
     mleko[9].reg = "Wysokie";
     mleko[9].lastname = "Janik";
     mleko[9].name = "Dorota";
     mleko[9].dob = "1974-01-29";
     mleko[9].liter = 558;
     mleko[9].fat = 3.5;
     mleko[9].klasa = "I";
     */
    for (int i = 0; i < 10; ++i) {
        cout.width(10);
        cout << mleko[i].lastname;
        cout.width(10);
        cout << mleko[i].name;
        cout.width(5);
        cout << mleko[i].liter << endl;
    }
    
    // suma
    int sum = 0;
    for (int i = 0; i < 10; ++i)
        sum += mleko[i].liter;
    cout << "sum: " << sum << endl;
    
    // srednia
    double average = 0;
    for (int i = 0; i < 10; ++i)
        average += mleko[i].fat;
    cout << "average: " << average/10 << endl;
    
    // srednia wazona tluszczu
    double weight = 0;
    for (int i = 0; i < 10; ++i)
        weight += mleko[i].liter * mleko[i].fat;
    cout << "wazona: " << weight/sum << endl;
    
    
    
    // wyplata
    for (int i = 0; i < 10; ++i) {
        mleko[i].wyplata = 1.15 * mleko[i].liter;
        if (mleko[i].liter > 150) mleko[i].wyplata += 0.5 * mleko[i].liter;
        if (mleko[i].fat < 3.8) mleko[i].wyplata += 0.4 * mleko[i].liter;
        if (mleko[i].klasa == "E" || mleko[i].klasa == "I") mleko[i].wyplata += 0.3 * mleko[i].liter;
    }
    for (int i = 0; i < 10; ++i) {
        cout.width(10);
        cout << mleko[i].lastname;
        cout.width(10);
        cout << mleko[i].name;
        cout.width(10);
        cout << mleko[i].wyplata << endl;
    }
    
    for (int i = 0; i < 10; ++i)
        if (mleko[i].dob[5] == '0' && mleko[i].dob[6] == '9')
            cout << "09 " << mleko[i].lastname << " " << mleko[i].name << endl;
    
    int sumM = 0, sumK = 0;
    for (int i = 0; i < 10; ++i) {
        if (mleko[i].name.back() == 'a') sumK += mleko[i].liter;
        else sumM += mleko[i].liter;
    }
    
    cout << "M " << sumM << endl;
    cout << "K " << sumK << endl;
    
    return 0;
}
