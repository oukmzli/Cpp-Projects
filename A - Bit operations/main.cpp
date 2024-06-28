#include "bitwise_operations.h"
#include <iostream>
using namespace std;

int main() {
    cout << Cardinality(50) << endl;
    
    char ch[200];
    Print(0, ch);
    for (int i = 0; ch[i] != '\0'; ++i) {
        cout << ch[i];
    }
    
    cout << endl;
    return 0;
}
