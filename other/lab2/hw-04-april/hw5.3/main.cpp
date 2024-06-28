#include <iostream>
#include <cstdarg>
#include <fstream>

class OBJECT_CLASS {
public:
    int* array;
    unsigned int size;
    
    OBJECT_CLASS() {
        size = 0;
        array = nullptr;
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
    
    ~OBJECT_CLASS() {
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
        element = OBJECT_CLASS(other.element);
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
    
    /*
    // Konstruktor z argumentem przekazywanym przez referencję
    ELEMENT_CLASS(const OBJECT_CLASS& obj) {
        element = obj;
        prev = nullptr;
        next = nullptr;
    }
    */
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
    
    ~ELEMENT_CLASS() {
        
    }
};

class DOUBLE_LINKED_LIST_CLASS {
private:
    ELEMENT_CLASS head;
    ELEMENT_CLASS* last;
    
public:
    unsigned int elements;
    unsigned int integers;
    
    void append(int value) {
        OBJECT_CLASS tempObj(&value, 1);
        append(tempObj);
    }
    
    void append(const OBJECT_CLASS& obj) {
        ELEMENT_CLASS* newElement = new ELEMENT_CLASS(obj);
        newElement->prev = last;
        newElement->next = &head;
        last->next = newElement;
        head.prev = newElement;
        last = newElement;
        elements++;
    }
    
    // Konstruktor domniemany
    DOUBLE_LINKED_LIST_CLASS() {
        elements = 0;
        integers = 0;
        head.next = &head;
        head.prev = &head;
        last = &head;
    }
    
    // Konstruktor kopiujący przez wskaźnik
    DOUBLE_LINKED_LIST_CLASS(DOUBLE_LINKED_LIST_CLASS* other) : DOUBLE_LINKED_LIST_CLASS() {
        if (other != nullptr) {
            for (ELEMENT_CLASS* ptr = other->head.next; ptr != &other->head; ptr = ptr->next) {
                append(ptr->element);
            }
        }
    }
    
    // Konstruktor kopiujący przez wartość
    DOUBLE_LINKED_LIST_CLASS(const DOUBLE_LINKED_LIST_CLASS& other) : DOUBLE_LINKED_LIST_CLASS() {
        for (ELEMENT_CLASS* ptr = other.head.next; ptr != &other.head; ptr = ptr->next) {
            append(ptr->element);
        }
    }
    
    // Konstruktor z nieokreśloną liczbą argumentów int
    DOUBLE_LINKED_LIST_CLASS(int count, ...) : DOUBLE_LINKED_LIST_CLASS() {
        va_list args;
        va_start(args, count);
        for (int i = 0; i < count; i++) {
            int value = va_arg(args, int);
            append(value);
        }
        va_end(args);
    }
    
    // Konstruktor z pliku
    DOUBLE_LINKED_LIST_CLASS(const std::string& filename) : DOUBLE_LINKED_LIST_CLASS() {
        std::ifstream file(filename);
        int value;
        while (file >> value) {
            append(value);
        }
        file.close();
    }
    
    void Create(int count, ...) {
        va_list args;
        va_start(args, count);
        for (int i = 0; i < count; i++) {
            int value = va_arg(args, int);
            ELEMENT_CLASS* newElement = new ELEMENT_CLASS(value);
            if (last == &head) {
                head.next = newElement;
                head.prev = newElement;
                newElement->next = &head;
                newElement->prev = &head;
            } else {
                last->next = newElement;
                newElement->prev = last;
                newElement->next = &head;
                head.prev = newElement;
            }
            last = newElement;
            elements++;
        }
        va_end(args);
    }
    
    void InsertAfter(ELEMENT_CLASS* after, int count, ...) {
        if (after == nullptr) return;
        va_list args;
        va_start(args, count);
        ELEMENT_CLASS* current = after;
        for (int i = 0; i < count; i++) {
            int value = va_arg(args, int);
            OBJECT_CLASS obj(&value, 1);
            ELEMENT_CLASS* newElement = new ELEMENT_CLASS(obj);
            newElement->next = current->next;
            newElement->prev = current;
            current->next->prev = newElement;
            current->next = newElement;
            current = newElement;
            elements++;
        }
        va_end(args);
    }
    
    void InsertBefore(ELEMENT_CLASS* before, int count, ...) {
        if (before == nullptr) return;
        va_list args;
        va_start(args, count);
        ELEMENT_CLASS* current = before;
        for (int i = 0; i < count; i++) {
            int value = va_arg(args, int);
            OBJECT_CLASS obj(&value, 1);
            ELEMENT_CLASS* newElement = new ELEMENT_CLASS(static_cast<OBJECT_CLASS*>(&obj));
            newElement->prev = current->prev;
            newElement->next = current;
            current->prev->next = newElement;
            current->prev = newElement;
            current = newElement;
            elements++;
        }
        va_end(args);
    }
    
    ~DOUBLE_LINKED_LIST_CLASS() {
        std::ofstream file("output.txt");
        
        if (file.is_open()) {
            for (ELEMENT_CLASS* ptr = head.next; ptr != &head;) {
                for (unsigned int i = 0; i < ptr->element.size; i++) {
                    file << ptr->element.array[i] << (i + 1 < ptr->element.size ? " " : "\n");
                }
                
                ELEMENT_CLASS* next = ptr->next;
                delete ptr;
                ptr = next;
            }
            
            file.close();
        } else {
            std::cerr << "nie udalo sie stworzyc/otworzyc pliku" << std::endl;
        }
        
        head.next = &head;
        head.prev = &head;
    }
};
