#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;
    
    // NWD
    int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
    
    // redukcja ulamka
    void reduce() {
        if (denominator == 0) {
            cout << "denominator cannot be zero." << endl;
            return;
        }
        
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
        
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    
public:
    Fraction(int num = 0, int denom = 1) {
        numerator = num;
        denominator = denom;
        
        reduce();
    }
    
    Fraction(float val) {
        const int precision = 1000000;
        numerator = val * precision;
        denominator = precision;
        
        if (val < 0) numerator = -numerator;
        reduce();
    }
    
    
    // operator wyjscia
    friend ostream& operator<<(ostream& os, const Fraction& f) {
        if (f.denominator == 1) {
            os << f.numerator;
        } else {
            os << f.numerator << '/' << f.denominator;
        }
        return os;
    }
    
    // operator wejscia
    friend istream& operator>>(istream& is, Fraction& f) {
        char slash;
        is >> f.numerator >> slash >> f.denominator;
        f.reduce();
        return is;
    }
    
    // +
    Fraction operator+(const Fraction& other) const {
        int common_denom = denominator * other.denominator;
        int num = numerator * other.denominator + other.numerator * denominator;
        return Fraction(num, common_denom);
    }
    
    Fraction operator+(int value) const {
        return *this + Fraction(value);
    }
    
    Fraction operator+(float value) const {
        return *this + Fraction(value);
    }
    
    // -
    Fraction operator-(const Fraction& other) const {
        int common_denom = denominator * other.denominator;
        int num = numerator * other.denominator - other.numerator * denominator;
        return Fraction(num, common_denom);
    }
    
    Fraction operator-(int value) const {
        return *this - Fraction(value);
    }
    
    Fraction operator-(float value) const {
        return *this - Fraction(value);
    }
    
    // *
    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }
    
    Fraction operator*(int value) const {
        return *this * Fraction(value);
    }
    
    Fraction operator*(float value) const {
        return *this * Fraction(value);
    }
    
    // /
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            cout << ("cannot divide by 0.") << endl;
            return *this;
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }
    
    Fraction operator/(int value) const {
        return *this / Fraction(value);
    }
    
    Fraction operator/(float value) const {
        return *this / Fraction(value);
    }
    
    // (-)
    Fraction operator-() const {
        return Fraction(-numerator, denominator);
    }
    
    // bitowe <<
    Fraction operator<<(int shift) const {
        int shift_value = 1 << shift; // 2^shift
        Fraction result = *new Fraction(numerator * shift_value, denominator * shift_value);
        result.reduce();
        return result;
    }
    
    // bitowe >>
    Fraction operator>>(int shift) const {
        int shift_value = 1 << shift; // 2^shift
        Fraction result = *new Fraction(numerator / shift_value, denominator / shift_value);
        result.reduce();
        return result;
    }
    
    // *=
    Fraction& operator*=(const Fraction& other) {
        numerator *= other.numerator;
        denominator *= other.denominator;
        reduce();
        return *this;
    }
    
    // /=
    Fraction& operator/=(const Fraction& other) {
        if (other.numerator == 0) {
            cout << ("cannot divide by 0.") << endl;
            return *this;
        }
        numerator *= other.denominator;
        denominator *= other.numerator;
        reduce();
        return *this;
    }
    
    // ++ postfix
    Fraction& operator++() {
        numerator += denominator;
        reduce();
        return *this;
    }
    
    // ++ prefix
    Fraction operator++(int) {
        Fraction temp(*this);
        ++(*this);
        return temp;
    }
    
    // -- postfix
    Fraction& operator--() {
        numerator -= denominator;
        reduce();
        return *this;
    }
    
    // -- prefix
    Fraction operator--(int) {
        Fraction temp(*this);
        --(*this);
        return temp;
    }
    
    // relacyjne
    // ==
    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }
    
    bool operator==(int value) const {
        return *this == Fraction(value);
    }
    
    bool operator==(float value) const {
        return *this == Fraction(value);
    }
    
    // !=
    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }
    
    bool operator!=(int value) const {
        return *this != Fraction(value);
    }
    
    bool operator!=(float value) const {
        return *this != Fraction(value);
    }
    
    // <
    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }
    
    bool operator<(int value) const {
        return *this < Fraction(value);
    }
    
    bool operator<(float value) const {
        return *this < Fraction(value);
    }
    
    // >
    bool operator>(const Fraction& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }
    
    bool operator>(int value) const {
        return *this > Fraction(value);
    }
    
    bool operator>(float value) const {
        return *this > Fraction(value);
    }
    
    // przypisanie
    Fraction& operator=(const Fraction& other) {
        numerator = other.numerator;
        denominator = other.denominator;
        return *this;
    }
};

int main() {
    /*
     Fraction f1(1, 2), f2(3, 4);
     cout << "sum: " << f1 + f2 << endl;
     cout << "difference: " << f1 - f2 << endl;
     cout << "product: " << f1 * f2 << endl;
     cout << "division: " << f1 / f2 << endl;
     cout << "negative: " << -f1 << endl;
     
     cout << "f1: " << f1 << endl;
     cout << "left shift (1): " << (f1 << 1) << endl;
     cout << "right shift (1): " << (f1 >> 1) << endl;
     
     ++f1;
     cout << "after ++: " << f1 << endl;
     f1--;
     cout << "after --: " << f1 << endl;
     
     f1 *= Fraction(2, 3);
     cout << "after *= Fraction(2, 3): " << f1 << endl;
     f1 /= Fraction(1, 2);
     cout << "after /= Fraction(1, 2): " << f1 << endl;
     
     Fraction f3(1, 2), f4(3, 4);
     cout << f3 << " == " << f4 << ": " << (f3 == f4) << endl;
     cout << f3 << " != " << f4 << ": " << (f3 != f4) << endl;
     cout << f3 << " < " << f4 << ": " << (f3 < f4) << endl;
     cout << f3 << " > " << f4 << ": " << (f3 > f4) << endl;
     
     Fraction f5 = f4;
     cout << "f4: " << f4 << endl;
     cout << "f5 = f4: " << f5 << endl;
     */
    Fraction f1(1, 2), f2(0, 1);
    int x = 5;
    f2 *= f1 * (x + 1);
    cout << "& f2: " << f2  << " f1: " << f1 << endl;
    //f2 *= f1 *= (f2 + 1);
    f2 = f1 / f2;
    cout << "f2: " << f2  << " f1: " << f1 << endl;
    
    
    
    return 0;
}
