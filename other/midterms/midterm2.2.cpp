#include <iostream>

using namespace std;

class PARAMETERS_CLASS {
protected:
    int rows;
    int cols;

    PARAMETERS_CLASS(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
    }

};

class ELEMENTS_CLASS {
protected:
    int size;
    int *matrix;

    ELEMENTS_CLASS(int size) {
        this->size = size;
        matrix = new int[size];
        for (int i = 0; i < size; ++i) {
            matrix[i] = 0;
        }
    }

    // 2x2
    ELEMENTS_CLASS(int size, int a0, int a1, int a2, int a3) {
        this->size = size;
        matrix = new int[size];
        if (size >= 1) {
            matrix[0] = a0;
        }
        if (size >= 2) {
            matrix[1] = a1;
        }
        if (size == 4) {
            matrix[2] = a2;
            matrix[3] = a3;
        }
    }

    // konstruktory dla innej interpretacji OPTYMALNOSCI PAMIECIOWEJ
    /*
     // 1x1
    ELEMENTS_CLASS(int size, int a0) {
        this->size = size;
        matrix = new int[size];
        if (size == 1) {
            matrix[0] = a0;
        }
    }
    // 1x2, 2x1
    ELEMENTS_CLASS(int size, int a0, int a1) {
        this->size = size;
        matrix = new int[size];
        if (size >= 1) {
            matrix[0] = a0;
        }
        if (size == 2) {
            matrix[1] = a1;
        }
    }
    */

    ELEMENTS_CLASS(const ELEMENTS_CLASS &other) {
        size = other.size;
        matrix = new int[size];
        for (int i = 0; i < size; ++i) {
            matrix[i] = other.matrix[i];
        }
    }

    ELEMENTS_CLASS &operator=(const ELEMENTS_CLASS &e) {
        if (this != &e) {
            size = e.size;
            delete[] matrix;
            matrix = new int[size];
            for (int i = 0; i < size; ++i) {
                matrix[i] = e.matrix[i];
            }
        }
        return *this;
    }

    ~ELEMENTS_CLASS() {
        delete[] matrix;
    }

};

class MATRIX_CLASS : public PARAMETERS_CLASS, public ELEMENTS_CLASS {
public:
    MATRIX_CLASS(int r, int c) :
            PARAMETERS_CLASS(isInBounds(r, c) ? r : 1, isInBounds(r, c) ? c : 1),
            ELEMENTS_CLASS(isInBounds(r, c) ? r * c : 1) {}

    // zakladajac, ze OPTYMALNOSC PAMIECIOWA dotyczy wylacznie struktury MACIERZY - uzywamy tego konstruktora:
    MATRIX_CLASS(int r, int c, int a0, int a1 = 0, int a2 = 0, int a3 = 0) :
            PARAMETERS_CLASS(isInBounds(r, c) ? r : 1, isInBounds(r, c) ? c : 1),
            ELEMENTS_CLASS(isInBounds(r, c) ? r * c : 1, a0, a1, a2, a3) {}


    // jesli jednak OPTYMALNOSC PAMIECIOWA inpretertowana jest w sensie "nie uzywamy ZBEDNYCH ZMIENNYCH" - musimy stworzyc trzy konstruktory:
    /*
     // 1x1
    MATRIX_CLASS(int r, int c, int a0) :
            PARAMETERS_CLASS(isInBounds(r, c) ? r : 1, isInBounds(r, c) ? c : 1),
            ELEMENTS_CLASS(isInBounds(r, c) ? r * c : 1, a0) {}
    // 1x2, 2x1
    MATRIX_CLASS(int r, int c, int a0, int a1) :
            PARAMETERS_CLASS(isInBounds(r, c) ? r : 1, isInBounds(r, c) ? c : 1),
            ELEMENTS_CLASS(isInBounds(r, c) ? r * c : 1, a0, a1) {}
    // 2x2
    MATRIX_CLASS(int r, int c, int a0, int a1, int a2, int a3) :
            PARAMETERS_CLASS(isInBounds(r, c) ? r : 1, isInBounds(r, c) ? c : 1),
            ELEMENTS_CLASS(isInBounds(r, c) ? r * c : 1, a0, a1, a2, a3) {}
    */

    // innym rozwiazaniem moglo by byc zczytywanie elementow z konsoli. Mozna to zrobic przeladowaniem operatora wejscia >>, ale to by bylo sprzeczne z warunkiem zadania.
    // Uwaga jest taka, ze z taka opcja trzeba by bylo nieco zmienic logike mnozenia (*) ze wzgledu na jej opartosc o pierwszy konstruktor MATRIX_CLASS(int r, int c), tworzacy macierz zerowa.
    /*
    MATRIX_CLASS(int r, int c) :
            PARAMETERS_CLASS(isInBounds(r, c) ? r : 1, isInBounds(r, c) ? c : 1),
            ELEMENTS_CLASS(isInBounds(r, c) ? r * c : 1) {
        cout << "Enter matrix elements:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "[" << i + 1 << "]" << " [" << j + 1 << "]: ";
                cin >> matrix[i * cols + j];
            }
        }
    }
    */

    bool isInBounds(int r, int c) {
        return !(r < 1 || c < 1 || r > 2 || c > 2);
    }

    MATRIX_CLASS operator*(const MATRIX_CLASS &m) const {
        if (cols != m.rows) {
            return MATRIX_CLASS(1, 1);
        }
        MATRIX_CLASS result = MATRIX_CLASS(rows, m.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < m.cols; ++j) {
                int sum = 0;
                for (int k = 0; k < cols; ++k) {
                    sum += matrix[i * cols + k] * m.matrix[k * m.cols + j];
                }
                result.matrix[i * m.cols + j] = sum;
            }
        }
        return result;
    }

    // przeladowanie operatora = podstawiania mozna latwo umiescic w przeladowanie operatora *=, ale moim zdaniem takie rozwiazanie jest lakoniczne,
    // a poza tym spelnia warunek zadania i sluzy poprawnosci dzialania programu oraz zgodnosci z wymaganiami
    MATRIX_CLASS &operator=(const MATRIX_CLASS &m) {
        if (this != &m) {
            PARAMETERS_CLASS::operator=(m);
            ELEMENTS_CLASS::operator=(m);
        }
        return *this;
    }

    MATRIX_CLASS &operator*=(const MATRIX_CLASS &m) {
        MATRIX_CLASS result = *this * m;
        *this = result;
        return *this;
    }

    MATRIX_CLASS &operator--() {
        for (int i = 0; i < cols; ++i) {
            --matrix[0 * cols + i];
        }
        return *this;
    }

    MATRIX_CLASS operator++(int) {
        MATRIX_CLASS temp(*this);
        for (int i = 0; i < rows; ++i) {
            ++matrix[i * cols + cols - 1];
        }
        return temp;
    }

    friend ostream &operator<<(ostream &os, const MATRIX_CLASS &m) {
        for (int i = 0; i < m.rows; ++i) {
            for (int j = 0; j < m.cols; ++j) {
                os << m.matrix[i * m.cols + j] << " ";
            }
            os << endl;
        }
        return os;
    }
};

int main() {
    MATRIX_CLASS a(2, 2, 1, 2, 3, 4), b(2, 2, 5, 6, 7, 8);
    cout << "A:\n" << a;
    cout << "B:\n" << b;
    cout << "A * B:\n" << a * b;
    a *= b;
    cout << "A *= B:\n" << a;
    cout << "--A:\n" << --a;
    cout << "B++:\n" << b++;
    cout << "B:\n" << b;

    cout << endl;
    MATRIX_CLASS c(1, 2, 1, 2), d(1, 2, 3, 4), e(2, 2, 3, 4, 5, 6);
    cout << "C:\n" << c;
    cout << "D:\n" << d;
    cout << "E:\n" << e;
    cout << "C(1x2) * D(1x2):\n" << c * d;
    cout << "C(1x2) * E(2x1):\n" << c * e;

    // testowanie zczytywania macierzy z konsoli:
    /*
    MATRIX_CLASS a(2,2);
    cout << "A:\n" << a;
     */
    return 0;
}
