#include <iostream>
using namespace std;

int main() {
    int a[10];
    cout << "Enter array elements: ";
    for (int i = 0; i < 10; ++i) cin >> a[i];
    
    cout << "first element: " << *a << "\n";
    cout << "fifth element: " << *a+4 << "\n";
    for (int i = 0; i < 10; ++i) cout << i+1 << ":\t" << *a+i << "\n";
    return 0;
}
