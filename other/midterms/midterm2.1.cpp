#include <iostream>
#include <cstring>
#include <cstdlib>

class STRING_CLASS {
private:
    char* str;
    size_t length;
    static unsigned int stringsCount;
    
public:
    STRING_CLASS() {
        str = new char[1];
        *str = '\0';
        length = 0;
        stringsCount++;
    }
    
    STRING_CLASS(const STRING_CLASS& other) {
        length = other.length;
        str = new char[length + 1];
        memcpy(str, other.str, length + 1);
        stringsCount++;
    }
    
    STRING_CLASS(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
        stringsCount++;
    }
    
    ~STRING_CLASS() {
        delete[] str;
        stringsCount--;
    }
    
    void setString(const char* s) {
        if (s == nullptr) stringsCount++;
        if (s != nullptr) delete[] str;
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }
    
    char* getString() {
        return str;
    }
    
    void setLenght(size_t newLenght) {
        length = newLenght;
    }
    
    static unsigned int StringsAmount() {
        return stringsCount;
    }
    
    
};

class ARRAY_2D_CLASS {
private:
    STRING_CLASS* array;
    unsigned int rows;
    unsigned int cols;
    static unsigned int arraysCount;
    
public:
    ARRAY_2D_CLASS() {
        array = new STRING_CLASS[1];
        rows = 0;
        cols = 0;
        arraysCount++;
    }
    
    ARRAY_2D_CLASS(const ARRAY_2D_CLASS &other) {
        rows = other.rows;
        cols = other.cols;
        array = new STRING_CLASS[rows * cols];
        for (unsigned int i = 0; i < rows * cols; i++) {
            array[i].setString(other.array[i].getString());
        }
        arraysCount++;
    }
    
    ARRAY_2D_CLASS(const char** data, unsigned int r, unsigned int c) {
        rows = r;
        cols = c;
        array = new STRING_CLASS[rows * cols];
        for (unsigned int i = 0; i < rows; i++) {
            for (unsigned int j = 0; j < cols; j++) {
                array[i * cols + j].setString(data[i]);
            }
        }
        arraysCount++;
    }
    
    ~ARRAY_2D_CLASS() {
        delete[] array;
        arraysCount--;
    }
    
    char* getElement(unsigned int row, unsigned int col) const {
        return array[row * cols + col].getString();
    }
    
    void setElement(unsigned int row, unsigned int col, const char* str) {
        STRING_CLASS temp(str);
        array[row * cols + col].setString(temp.getString());
    }
    
    void insertColumn(unsigned int col, const char* newCol[]) {
        if (col > cols) return;
        STRING_CLASS* newArray = new STRING_CLASS[rows * (cols + 1)];
        unsigned int newCols = cols + 1;
        
        for (unsigned int i = 0; i < rows; i++) {
            for (unsigned int j = 0; j < newCols; j++) {
                if (j < col) {
                    newArray[i * newCols + j].setString(array[i * cols + j].getString());
                } else if (j > col) {
                    newArray[i * newCols + j].setString(array[i * cols + (j - 1)].getString());
                } else {
                    newArray[i * newCols + j].setString(newCol[i]);
                }
            }
        }
        
        delete[] array;
        array = newArray;
        cols = newCols;
    }
    
    void eraseColumn(unsigned int col) {
        if (col >= cols) return;
        STRING_CLASS* newArray = new STRING_CLASS[rows * (cols - 1)];
        unsigned int newCols = cols - 1;
        
        for (unsigned int i = 0; i < rows; i++) {
            for (unsigned int j = 0; j < cols; j++) {
                if (j < col) {
                    newArray[i * newCols + j].setString(array[i * cols + j].getString());
                } else if (j > col) {
                    newArray[i * newCols + j - 1].setString(array[i * cols + j].getString());
                }
            }
        }
        
        delete[] array;
        array = newArray;
        cols = newCols;
    }
    
    
    void insertRow(unsigned int row, const char* newRow[]) {
        if (row > rows) return;
        STRING_CLASS* newArray = new STRING_CLASS[(rows + 1) * cols];
        unsigned int newRows = rows + 1;
        
        for (unsigned int i = 0; i < newRows; i++) {
            for (unsigned int j = 0; j < cols; j++) {
                if (i < row) {
                    newArray[i * cols + j].setString(array[i * cols + j].getString());
                } else if (i > row) {
                    newArray[i * cols + j].setString(array[(i - 1) * cols + j].getString());
                } else {
                    newArray[i * cols + j].setString(newRow[j]);
                }
            }
        }
        
        delete[] array;
        array = newArray;
        rows = newRows;
    }
    
    void eraseRow(unsigned int row) {
        if (row >= rows) return;
        STRING_CLASS* newArray = new STRING_CLASS[(rows - 1) * cols];
        unsigned int newRows = rows - 1;
        
        for (unsigned int i = 0; i < rows; i++) {
            if (i == row) continue;
            for (unsigned int j = 0; j < cols; j++) {
                if (i < row) {
                    newArray[i * cols + j].setString(array[i * cols + j].getString());
                } else if (i > row) {
                    newArray[(i - 1) * cols + j].setString(array[i * cols + j].getString());
                }
            }
        }
        
        delete[] array;
        array = newArray;
        rows = newRows;
    }
    
    
    static unsigned int arraysAmount() {
        return arraysCount;
    }
};

unsigned int STRING_CLASS::stringsCount = 0;
unsigned int ARRAY_2D_CLASS::arraysCount = 0;

int main() {
    // Testing STRING_CLASS
    std::cout << "Testing STRING_CLASS..." << std::endl;
    STRING_CLASS string1("Hello, World!");
    std::cout << "string1: " << string1.getString() << std::endl;
    
    STRING_CLASS string2 = string1; // Copy constructor
    std::cout << "string2 (copy of string1): " << string2.getString() << std::endl;
    
    string2.setString("Goodbye, World!");
    std::cout << "string2 after modification: " << string2.getString() << std::endl;
    std::cout << "string1 should remain unchanged: " << string1.getString() << std::endl;
    
    // Testing ARRAY_2D_CLASS
    std::cout << "\nTesting ARRAY_2D_CLASS..." << std::endl;
    const char* initData[2] = {"Row 1, Col 1", "Row 1, Col 2"};
    ARRAY_2D_CLASS array2D(initData, 1, 2);
    std::cout << "Initial array: " << array2D.getElement(0, 0) << ", " << array2D.getElement(0, 1) << std::endl;
    
    const char* newRow[] = {"New Row, Col 1"};
    array2D.insertRow(1, newRow);
    std::cout << "After inserting a row:\t\t" << array2D.getElement(1, 0) << ", " << array2D.getElement(1, 1) << std::endl;
    
    array2D.eraseRow(0);
    std::cout << "After erasing the new row:\t" << array2D.getElement(0, 0) << ", " << array2D.getElement(0, 1) << std::endl;
    
    // Output number of active strings and arrays
    std::cout << "\nActive strings: " << STRING_CLASS::StringsAmount() << std::endl;
    std::cout << "Active arrays: " << ARRAY_2D_CLASS::arraysAmount() << std::endl;
    
    return 0;
}
