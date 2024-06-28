#include <iostream>
#include <cstdarg>
using namespace std;

int abs(int x) {
    return x < 0 ? -x : x;
}

int gcd(int a, int b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}

int polynomalGCD(int *arr, int size) {
    int result = arr[0];
    for (int i = 1; i < size; i++) {
        result = gcd(arr[i], result);
        if (result == 1) {
            return 1;
        }
    }
    
    return abs(result);
}

class POLYNOMIAL {
public:
    int* coefficients;
    int degree;
    static int overloaded;
    
    POLYNOMIAL() {
        coefficients = new int[1];
        coefficients[0] = 0;
        degree = 0;
    }
    
    POLYNOMIAL(int n, ...) {
        degree = n;
        coefficients = new int[n + 1];
        
        va_list arguments;
        va_start(arguments, n);
        
        for (int i = 0; i <= n; i++) {
            coefficients[i] = va_arg(arguments, int);
        }
        
        va_end(arguments);
        
        normalize();
    }
    
    POLYNOMIAL(const POLYNOMIAL &other) {
        degree = other.degree;
        coefficients = new int[degree + 1];
        for (int i = 0; i < other.degree + 1; i++) {
            coefficients[i] = other.coefficients[i];
        }
    }
    
    ~POLYNOMIAL() {}
    
    void decreaseDegree() {
        if (degree == 0) return;
        
        while (degree > 0 && coefficients[degree] == 0) {
            degree--;
        }
        
        if (coefficients[degree] != 0) return;
        
        int *newCoefficients = new int[degree + 1];
        for (int i = 0; i < degree + 1; i++) {
            newCoefficients[i] = coefficients[i];
        }
        
        delete[] coefficients;
        coefficients = newCoefficients;
    }
    
    void normalize() {
        decreaseDegree();
        
        int gcd = polynomalGCD(coefficients, degree + 1);
        if (gcd == 0) return;
        
        for (int i = 0; i < degree + 1; i++) {
            coefficients[i] /= gcd;
        }
    }
    
    POLYNOMIAL &operator=(const POLYNOMIAL &other) {
        if (this == &other) return *this;
        degree = other.degree;
        coefficients = new int[degree + 1];
        for (int i = 0; i < other.degree + 1; i++) {
            coefficients[i] = other.coefficients[i];
        }
        return *this;
    }
    
    
    POLYNOMIAL operator+(const POLYNOMIAL &p) {
        int maxDegree = degree > p.degree ? degree : p.degree;
        int minDegree = degree < p.degree ? degree : p.degree;
        
        POLYNOMIAL result(maxDegree);
        delete[] result.coefficients;
        result.coefficients = new int[maxDegree + 1];
        
        for (int i = 0; i <= minDegree; ++i) {
            result.coefficients[i] = coefficients[i] + p.coefficients[i];
        }
        
        for (int i = minDegree + 1; i <= maxDegree; ++i) {
            result.coefficients[i] = (degree > p.degree) ? coefficients[i] : p.coefficients[i];
        }
        
        result.normalize();
        return result;
    }
    
    POLYNOMIAL operator-(const POLYNOMIAL &p) {
        int maxDegree = degree > p.degree ? degree : p.degree;
        int minDegree = degree < p.degree ? degree : p.degree;
        
        POLYNOMIAL result(maxDegree);
        delete[] result.coefficients;
        result.coefficients = new int[maxDegree + 1];
        
        for (int i = 0; i <= minDegree; ++i) {
            result.coefficients[i] = coefficients[i] - p.coefficients[i];
        }
        
        for (int i = minDegree + 1; i <= maxDegree; ++i) {
            if (degree > p.degree) {
                result.coefficients[i] = coefficients[i];
            } else {
                result.coefficients[i] = -p.coefficients[i];
            }
        }
        
        result.normalize();
        return result;
    }
    
    POLYNOMIAL operator*(const POLYNOMIAL &p) {
        int resultDegree = degree + p.degree;
        POLYNOMIAL result = POLYNOMIAL();
        delete[] result.coefficients;
        result.coefficients = new int[resultDegree + 1];
        result.degree = resultDegree;
        
        for (int i = 0; i <= resultDegree; i++) {
            result.coefficients[i] = 0;
        }
        
        for (int i = 0; i <= degree; i++) {
            for (int j = 0; j <= p.degree; j++) {
                result.coefficients[i + j] += coefficients[i] * p.coefficients[j];
            }
        }
        
        result.normalize();
        return result;
    }
    
    POLYNOMIAL operator/(const POLYNOMIAL &p) {
        if (p.degree == 0 && p.coefficients[0] == 0)
            return POLYNOMIAL();
        
        if (p.degree > degree)
            return POLYNOMIAL();
        
        int resultDegree = degree - p.degree;
        bool isNegative = (p.coefficients[p.degree] < 0) && ((degree - p.degree) % 2 == 1);
        
        POLYNOMIAL remainder(*this);
        POLYNOMIAL quotient;
        quotient.degree = resultDegree;
        delete[] quotient.coefficients;
        quotient.coefficients = new int[resultDegree + 1]();
        
        int pCoeff = p.coefficients[p.degree];
        int originalDegree = degree;
        
        while (degree >= p.degree) {
            int remainderCoeff = remainder.coefficients[degree];
            quotient.coefficients[degree - p.degree] = remainderCoeff;
            
            for (int i = p.degree; i > 0; --i) {
                remainder.coefficients[degree - i] = remainder.coefficients[degree - i] * pCoeff - quotient.coefficients[degree - p.degree] * p.coefficients[p.degree - i];
            }
            
            for (int i = 0; i < degree - p.degree; ++i) {
                remainder.coefficients[i] *= pCoeff;
            }
            
            for (int i = quotient.degree; i >= degree - p.degree; --i) {
                quotient.coefficients[i] *= pCoeff;
            }
            
            degree--;
        }
        
        if (isNegative) {
            for (int i = 0; i <= quotient.degree; ++i) {
                quotient.coefficients[i] = -quotient.coefficients[i];
            }
        }
        
        degree = originalDegree;
        quotient.normalize();
        
        return quotient;
    }
    
    POLYNOMIAL operator%(const POLYNOMIAL &p) {
        if (p.degree > degree)
            return *this;
        
        if (p.degree == 0 || degree == 0)
            return POLYNOMIAL();

        int targetDegree = degree - p.degree;
        int newRemainderDegree = p.degree - 1;

        POLYNOMIAL quotient;
        POLYNOMIAL remainder(*this);

        quotient.degree = targetDegree;
        delete[] quotient.coefficients;
        quotient.coefficients = new int[quotient.degree + 1];
        for (int i = 0; i <= quotient.degree; i++) {
            quotient.coefficients[i] = 0;
        }

        int pCoeff = p.coefficients[p.degree];
        int originalDegree = degree;

        while (degree >= p.degree) {
            quotient.coefficients[degree - p.degree] = remainder.coefficients[degree];
            
            for (int i = p.degree; i > 0; i--) {
                remainder.coefficients[degree - i] = remainder.coefficients[degree - i] * pCoeff - quotient.coefficients[degree - p.degree] * p.coefficients[p.degree - i];
            }
            
            for (int i = 0; i < degree - p.degree; i++) {
                remainder.coefficients[i] *= pCoeff;
            }
            
            for (int i = quotient.degree; i >= degree - p.degree; i--) {
                quotient.coefficients[i] *= pCoeff;
            }
            
            degree--;
        }

        degree = originalDegree;

        remainder.degree = newRemainderDegree;
        
        int* updatedCoefficients = new int[remainder.degree + 1];
        for (int i = 0; i <= remainder.degree; i++) {
            updatedCoefficients[i] = remainder.coefficients[i];
        }
        delete[] remainder.coefficients;
        remainder.coefficients = updatedCoefficients;

        if ((degree - p.degree) % 2 == 0 && p.coefficients[p.degree] < 0) {
            remainder = -remainder;
        }

        remainder.normalize();
        return remainder;
    }





    
    
    POLYNOMIAL operator>>(int n) {
        if (n < 0 || (degree == 0 && coefficients[0] == 0)) {
            return POLYNOMIAL();
        }
        if (n == 0) {
            return *this;
        }
        
        POLYNOMIAL result(*this);
        result.degree += n;
        int* newcoefficients = new int[result.degree + 1];
        
        for (int i = 0; i <= result.degree; i++) {
            newcoefficients[i] = 0;
        }
        
        for (int i = 0; i <= degree; i++) {
            newcoefficients[i + n] = coefficients[i];
        }
        
        delete[] result.coefficients;
        result.coefficients = newcoefficients;
        result.normalize();
        return result;
    }
    
    POLYNOMIAL operator<<(int n) {
        if (n < 0 || (degree == 0 && coefficients[0] == 0)) {
            return POLYNOMIAL();
        }
        if (n == 0) {
            return *this;
        }
        if (n > degree) {
            return POLYNOMIAL();
        }
        
        POLYNOMIAL result(*this);
        result.degree -= n;
        int* newcoefficients = new int[result.degree + 1];
        
        for (int i = 0; i <= result.degree; i++) {
            newcoefficients[i] = coefficients[i + n];
        }
        
        delete[] result.coefficients;
        result.coefficients = newcoefficients;
        result.normalize();
        return result;
    }
    
    POLYNOMIAL operator-() {
        POLYNOMIAL result(*this);
        for (int i = 0; i < result.degree + 1; i++)
            result.coefficients[i] *= -1;
        return result;
    }
    
    POLYNOMIAL operator+=(const POLYNOMIAL &p) {
        *this = *this + p;
        return *this;
    }
    
    POLYNOMIAL operator-=(const POLYNOMIAL &p) {
        *this = *this - p;
        return *this;
    }
    
    POLYNOMIAL operator*=(const POLYNOMIAL &p) {
        *this = *this * p;
        return *this;
    }
    
    POLYNOMIAL operator/=(const POLYNOMIAL &p) {
        *this = *this / p;
        return *this;
    }
    
    POLYNOMIAL operator%=(const POLYNOMIAL &p) {
        *this = *this % p;
        return *this;
    }
    
    POLYNOMIAL &operator>>=(int n) {
        *this = *this >> n;
        return *this;
    }
    
    POLYNOMIAL &operator<<=(int n) {
        *this = *this << n;
        return *this;
    }
    
    POLYNOMIAL operator++(int) {
        POLYNOMIAL newPolynom(*this);
        for (int i = 0; i < degree + 1; i++)
            coefficients[i]++;
        normalize();
        return newPolynom;
    }
    
    POLYNOMIAL &operator++() {
        for (int i = 0; i < degree + 1; i++)
            coefficients[i]++;
        normalize();
        return *this;
    }
    
    POLYNOMIAL operator--(int) {
        POLYNOMIAL newPolynom(*this);
        for (int i = 0; i < degree + 1; i++)
            coefficients[i]--;
        normalize();
        return newPolynom;
    }
    
    POLYNOMIAL &operator--() {
        for (int i = 0; i < degree + 1; i++)
            coefficients[i]--;
        normalize();
        return *this;
    }
    
    void* operator new(size_t size) {
        overloaded++;
        void* ptr = ::operator new(size);
        return ptr;
    }
    
    void operator delete(void* ptr) {
        overloaded--;
        ::operator delete(ptr);
    }
    
    friend istream &operator>>(istream &is, POLYNOMIAL &p) {
        is >> p.degree;
        delete[] p.coefficients;
        p.coefficients = new int[p.degree + 1];
        for (int i = 0; i <= p.degree; ++i) {
            is >> p.coefficients[i];
        }
        p.normalize();
        return is;
    }
    
    
    friend ostream &operator<<(ostream &os, const POLYNOMIAL &p) {
        os << "( ";
        for (int i = 0; i <= p.degree; ++i) {
            os << p.coefficients[i];
            if (i < p.degree) {
                os << ", ";
            }
        }
        os << " )";
        return os;
    }
    
    friend bool operator==(const POLYNOMIAL &p, const POLYNOMIAL &q) {
        if (p.degree != q.degree) return false;
        
        for (int i = p.degree; i >= 0; i--) {
            if (p.coefficients[i] != q.coefficients[i])
                return false;
        }
        
        return true;
    }
    
    friend bool operator!=(const POLYNOMIAL &p, const POLYNOMIAL &q) {
        return !(p == q);
    }
    
    friend bool operator<(const POLYNOMIAL &p, const POLYNOMIAL &q) {
        if (p.degree < q.degree) return true;
        else if (p.degree > q.degree) return false;
        
        for (int i = p.degree; i >= 0; i--) {
            if (p.coefficients[i] < q.coefficients[i])
                return true;
            else if (p.coefficients[i] > q.coefficients[i])
                return false;
        }
        return false;
    }
    
    friend bool operator<=(const POLYNOMIAL &p, const POLYNOMIAL &q) {
        return (p < q || p == q);
    }
    
    friend bool operator>(const POLYNOMIAL &p, const POLYNOMIAL &q) {
        return q < p;
    }
    
    friend bool operator>=(const POLYNOMIAL &p, const POLYNOMIAL &q) {
        return (p > q || p == q);
    }
    
};


int POLYNOMIAL::overloaded = 0;
int main() {
    

     {
     cout << (POLYNOMIAL(2, 1, 2, -1) % POLYNOMIAL(2, 2, -6, 4)) << endl;
     //        CHECK_cout("( 3, 1 )");
     }
     
     
     {
     cout << (POLYNOMIAL(3, -7, 5, -3, 7) % POLYNOMIAL(3, 7, 6, 4, -2)) << endl;
     //        CHECK_cout("( 35, 52, 22 )");
     }
     
     
     {
     cout << (POLYNOMIAL(4, 4, 2, 5, -2, 1) % POLYNOMIAL(2, 3, -3, -4)) << endl;
     //        CHECK_cout("( 631, -379 )");
     }
     
     
     {
     cout << (POLYNOMIAL(6, 0, -5, -4, 6, 1, -4, 6) % POLYNOMIAL(3, 2, -5, 6, 7)) << endl;
     //        CHECK_cout("( 9256, -44147, 46941 )");
     }
     
     
     {
     cout << (POLYNOMIAL(6, -1, 0, 2, 1, 3, 0, -1) % POLYNOMIAL(5, -4, 3, 1, 4, -7, 5)) << endl;
     //        CHECK_cout("( -53, 1, 72, 58, 46 )");
     }
     

    /*
    {
        cout << (POLYNOMIAL(2, 2, 3, 5) / POLYNOMIAL(1, 1, 7)) << endl;
        //        CHECK_cout("( 16, 35 )");
    }
    
    {
        cout << (POLYNOMIAL(2, 7, 7, 5) / POLYNOMIAL(1, 2, -4)) << endl;
        //        CHECK_cout("( -19, -10 )");
    }
    
    {
        cout << (POLYNOMIAL(2, 1, 2, -1) / POLYNOMIAL(2, 2, -6, 4)) << endl;
        //        CHECK_cout("( -1 )");
    }
    
    {
        cout << (POLYNOMIAL(4, 4, 2, 5, -2, 1) / POLYNOMIAL(2, 3, -3, -4)) << endl;
        //        CHECK_cout("( -125, 44, -16 )");
    }
    
    {
        cout << (POLYNOMIAL(5, 1, -1, -4, -5, 0, -7) / POLYNOMIAL(1, 2, 4) )<< endl;
        //        CHECK_cout("( -11, -10, -108, 56, -112 )");
    }
    
    {
        cout << (POLYNOMIAL(5, 4, -4, -5, 2, -7, -7) / POLYNOMIAL(1, -4, 3) )<< endl;
        //        CHECK_cout("( -3712, -2541, -1602, -1323, -567 )");
    }
    
    {
        cout << (POLYNOMIAL(6, 0, -5, -4, 6, 1, -4, 6) / POLYNOMIAL(3, 2, -5, 6, 7) )<< endl;
        //        CHECK_cout("( -4628, 4501, -3136, 2058 )");
    }
    
    {
        cout << (POLYNOMIAL(6, -1, 0, 2, 1, 3, 0, -1) / POLYNOMIAL(5, -4, 3, 1, 4, -7, 5)) << endl;
        //        CHECK_cout("( -7, -5 )");
    }
     */
    return 0;
}
