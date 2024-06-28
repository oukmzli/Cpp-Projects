/*#include "Mult.h"
 //#include "Operation.h"
 #include <iostream>
 #include <string>
 
 int main() {
 const string strArray[] = {"1", "-1", "10000"};
 cout << Mult(3, strArray) << endl;
 
 return 0;
 }
 
 */
#include "Mult.h"
//#include "Operation.h"
#include <fstream>
#include <iostream>
#include <string>

std::string Mult(int num, ...);

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    
    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files!" << std::endl;
        return 1;
    }
    
    std::string term1;
    std::string term2;
    int i = 0;
    int num = 0;
    
    inputFile >> num;
    while (i < num) {
        inputFile >> term1 >> term2;
        outputFile << Mult(2, term1.c_str(), term2.c_str()) << '\n';
        i++;
    }
    
    inputFile.close();
    outputFile.close();
    
    return 0;
}


