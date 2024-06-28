#include <iostream>
#include <cstdarg>

class OBJECT_CLASS {
public:
    int* array;
    unsigned int size;

    OBJECT_CLASS() {
        array = nullptr;
        size = 0;
    }

    OBJECT_CLASS(int* arr, unsigned int n) {
        size = n;
        array = new int[size];
        for (unsigned int i = 0; i < size; i++) {
            array[i] = arr[i];
        }
    }
    
    OBJECT_CLASS(const OBJECT_CLASS& other) {
        size = other.size;
        array = new int[size];
        for (unsigned int i = 0; i < size; i++) {
            array[i] = other.array[i];
        }
    }

    OBJECT_CLASS(int num, ...) {
        va_list args;
        va_start(args, num);
        size = num;
        array = new int[size];
        for (unsigned int i = 0; i < size; i++) {
            array[i] = va_arg(args, int);
        }
        va_end(args);
    }

    void Destructor() {
        delete[] array;
        array = nullptr;
        size = 0;
    }
};

class ELEMENT_CLASS {
public:
    OBJECT_CLASS element;
    ELEMENT_CLASS* prev;
    ELEMENT_CLASS* next;

    // Konstruktor domyślny
    ELEMENT_CLASS() {
        prev = nullptr;
        next = nullptr;
    }
    // Konstruktor kopiujący
    ELEMENT_CLASS(const ELEMENT_CLASS& other) {
        element = other.element;
        prev = nullptr;
        next = nullptr;
    }


    // Konstruktor z argumentem przekazywanym przez wartość
    ELEMENT_CLASS(OBJECT_CLASS obj) {
        element = obj;
        prev = nullptr;
        next = nullptr;
    }

    // Konstruktor z argumentem przekazywanym przez wskaźnik
    ELEMENT_CLASS(OBJECT_CLASS* obj) {
        element = *obj;
        prev = nullptr;
        next = nullptr;
    }
    
    // Konstruktor z argumentem przekazywanym przez referencję
    ELEMENT_CLASS(const OBJECT_CLASS& obj) {
        element = obj;
        prev = nullptr;
        next = nullptr;
    }
    
    // Konstruktor ze zmienną liczbą argumentów wyłącznie typu int
    ELEMENT_CLASS(int num, ...) {
        prev = nullptr; next = nullptr;
        va_list args;
        va_start(args, num);
        int* arr = new int[num];
        for (int i = 0; i < num; i++) {
            arr[i] = va_arg(args, int);
        }
        va_end(args);
        element.array = arr;
        element.size = num;
    }

    void Destructor() {
        element.Destructor();
    }
};
