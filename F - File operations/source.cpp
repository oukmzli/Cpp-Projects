#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void SymmetricDifference (string firstFile, string secondFile, string thirdFile);

struct Data {
    int i;
    string s;
    char c;
    
    struct Component {
        bool b;
        unsigned int uc;
        float f;
    };
    
    Component c1; Component c2; Component c3; Component c4;
};

void skipLine(istream& file) {
    char ch;
    while (file.get(ch)) {
        if (ch == '\n') {
            break;
        }
    }
}

void readComponent(istream &file, Data::Component &comp) {
    int tempBool;
    file >> tempBool;
    comp.b = (tempBool != 0);
    file >> comp.uc;
    file >> comp.f;
}

void writeComponent(ostream &file, const Data::Component &comp) {
    file << (comp.b ? 1 : 0) << ' ' << comp.uc << ' ' << comp.f << '\n';
}

bool readData(istream& file, Data& data) {
    file >> data.i;
    skipLine(file);
    getline(file, data.s);
    file >> data.c;
    
    readComponent(file, data.c1);
    readComponent(file, data.c2);
    readComponent(file, data.c3);
    readComponent(file, data.c4);
    return !file.eof();
}

void writeData(ostream &file, const Data &data) {
    file << data.i << '\n';
    file << data.s << '\n' << data.c << '\n';
    writeComponent(file, data.c1);
    writeComponent(file, data.c2);
    writeComponent(file, data.c3);
    writeComponent(file, data.c4);
}


// ----------------------------------------------- \\
 
bool isNumInFile (istream& file, int num) {
    while (!file.eof()) {
        string str = ""; file >> str;
        if (str != "" && num == stoi(str)) return 1;
        skipLine(file);
    }
    return 0;
}

void increaseFrequency (fstream& file, int num) {
    while (!file.eof()) {
        string str = ""; file >> str;
        if (str != "" && num == stoi(str)) {
            file.get();
            str = ""; file >> str;
            file << stoi(str) + 1;
            break;
        }
    }
}

void SortCount (string firstFile, string secondFile, string thirdFile) {
    fstream file, temp, frequencies;
    Data data;
    
    file.open(firstFile.c_str(), fstream::in);
    temp.open(secondFile.c_str(), fstream::out | fstream::trunc);
    frequencies.open(thirdFile.c_str(), fstream::in);
    
    while (readData(file, data)) {
        writeData(temp, data);
        if (!isNumInFile(frequencies, data.i)) {
            frequencies << data.i << "\n" << 1;
        } else {
            string str = ""; frequencies >> str;
        }
        
    }
    
    temp.close();
    file.close();
    frequencies.close();
}




// ----------------------------------------------- \\



bool greaterThan(Data& a, Data& b, bool iORs) {
    if (iORs) {
        return a.i > b.i;
    } else {
        return a.s > b.s;
    }
}

void sorting(string firstFile, string secondFile, bool iORs) {
    bool swapped;
    fstream file, temp;
    Data currentData, nextData;
    
    do {
        swapped = false;
        file.open(firstFile.c_str(), fstream::in);
        temp.open(secondFile.c_str(), fstream::out | fstream::trunc);

        if (readData(file, currentData)) {
            while (readData(file, nextData)) {
                if (greaterThan(currentData, nextData, iORs)) {
                    writeData(temp, nextData);
                    swapped = true;
                } else {
                    writeData(temp, currentData);
                    currentData = nextData;
                }
            }
            writeData(temp, currentData);
        }

        file.close();
        temp.close();
        
        if (!swapped) {
            break;
        }

        swapped = false;
        temp.open(secondFile.c_str(), fstream::in);
        file.open(firstFile.c_str(), fstream::out | fstream::trunc);

        if (readData(temp, currentData)) {
            while (readData(temp, nextData)) {
                if (greaterThan(nextData, currentData, iORs)) {
                    writeData(file, currentData);
                    currentData = nextData;
                } else {
                    writeData(file, nextData);
                    swapped = true;
                }
            }
            writeData(file, currentData);
        }

        file.close();
        temp.close();

    } while (swapped);
}

void SortInt(string firstFile, string secondFile, string thirdFile) {
    sorting(firstFile, secondFile, 1);
}

void SortString(string firstFile, string secondFile, string thirdFile) {
    sorting(firstFile, secondFile, 0);
}


int main() {
    //SortInt("input.txt", "temp1.txt", "temp2.txt");
    fstream temp;
    temp.open("temp.txt");
    increaseFrequency(temp, 5);
    temp.close();
    return 0;
}
