// zad. 5
#include <iostream>
using namespace std;

long long int round (double n) {
    long long int temp = n;
    n -= temp;
    if (n >= 0.5) temp += + 1;
    else if (n <= (-0.5)) temp -= 1;
    return temp;
}


int main() {
    double a = -0.50;
    cout << round(a);
    
    return 0;
}

/*
// zad. 6
double func (double a, double b, double x) {
    return a * x +b;
}

// zad. 4
#include <iostream>
using namespace std;

int main() {
    int a(0), temp(0);
    int arr[100];
    for (int i = 0; i < 100; ++i) {
        temp = a;
        cin >> a;
        if (a == temp) break;
        arr[i] = a;
    }
    return 0;
}

/*
 
// zad. 3
#include <iostream>
using namespace std;

void fractionDubler (double &a) {
    int temp = a;
    a -= temp;
    a *= 2;
    a += temp;
}

int main() {
    double a = 322.60;
    fractionDubler(a);
    cout << a << "\n";
    
    return 0;
}
 
/*
 
// zad. 2
unsigned long long mirror (unsigned long long n) {
    unsigned long long mirrored = 0;
    int digit;
    while (n > 0) {
        digit = n % 10;
        mirrored = mirrored * 10 + digit;
        n /= 10;
    }
    return mirrored;
}

/*
// zad. 1
// A-Z : 65-90, a-z : 97-122
#include <iostream>
using namespace std;

int main() {
    char a; unsigned short sum = 0;
    while (sum <= 350) {
        cin >> a;
        if (((int)a > 64 && (int)a < 91) || (int(a) > 96 && (int)a < 123)) {
            sum += (int)a;
            cout << (int)a << " sum: " << sum << endl;
        }
    }
    return 0;
}
*/
