#include <iostream>

class OBJECT_CLASS {
public:
    int* array;

    // Konstruktor domyslny
    OBJECT_CLASS() {
        this->array = nullptr;
        this->size = 0;
    }

    // Konstruktor kopiujacy
    OBJECT_CLASS(const OBJECT_CLASS& other) {
        this->size = other.size;
        
        if (size > 0) {
            array = new int[size];
            for (int i = 0; i < size; i++)
                array[i] = other.array[i];
        } else {
            array = nullptr;
        }
    }

    // Destruktor
    void Destructor() {
        delete[] array;
        array = nullptr;
        size = 0;
    }

private:
    unsigned int size;
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
