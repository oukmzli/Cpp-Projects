#include <cstdarg>

class OBJECT_CLASS {
private:
    int* elements;
    int capacity;
    int length;
    
    void resize() {
        capacity += 1;
        int* newElements = new int[capacity];
        
        for (int i = 0; i < length; ++i) {
            newElements[i] = elements[i];
        }
        
        delete[] elements;
        elements = newElements;
    }
    
public:
    OBJECT_CLASS() {
        elements = nullptr;
        capacity = 0;
        length = 0;
    }
    
    // konstruktor kopiowania
    /*
    OBJECT_CLASS(const OBJECT_CLASS& other) {
        this->capacity = other.capacity;
        this->length = other.length;
        
        this->elements = new int[this->capacity];
        for (int i = 0; i < this->length; ++i) {
            this->elements[i] = other.elements[i];
        }
    }
    */
    
    void addElement(int element) {
        if (length == capacity) {
            resize();
        }
        elements[length++] = element;
    }
    
    int getLength() const {
        return length;
    }
    
    int getSum() const {
        int sum = 0;
        for (int i = 0; i < length; ++i) {
            sum += elements[i];
        }
        return sum;
    }
    
    void Destrcutor () {
        delete[] elements;
        capacity = 0;
        lenght = 0;
    }
};


class DoubleLinkedList {
private:
    class Node {
    public:
        OBJECT_CLASS object;
        Node* prev;
        Node* next;
        
        Node(const OBJECT_CLASS& object, Node* prev = nullptr, Node* next = nullptr) {
            this->object = object;
            this->prev = prev;
            this->next = next;
        }
    };
    
    Node* head;
    int size;
    int totalInts;
    
public:
    DoubleLinkedList() {
        head = nullptr;
        size = 0;
        totalInts = 0;
    }
    
    void addFront(const OBJECT_CLASS& object) {
        head = new Node(object, nullptr, head);
        if (head->next != nullptr) {
            head->next->prev = head;
        }
        size++;
        totalInts += object.getSum();
    }
    
    void insert(const OBJECT_CLASS& obj) {
        addFront(obj);
    }
    
    void insert(int num, ...) {
        va_list args;
        va_start(args, num);
        
        for (int i = 0; i < num; ++i) {
            OBJECT_CLASS* obj = va_arg(args, OBJECT_CLASS*);
            if (obj != nullptr) {
                addFront(*obj);
            }
        }
        
        va_end(args);
    }
    
    void insert(int position, const OBJECT_CLASS& object) {
        if (position < 0 || position > size) {
            // std::cout << "pozycja poza zakresem" << std::endl;
            return;
        }
        
        if (position == 0) {
            addFront(object);
            return;
        }
        
        Node* newNode = new Node(object);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 0; i < position - 1 && temp->next != nullptr; ++i) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        size++;
        totalInts += object.getSum();
    }
    
    int getSize() const {
        return size;
    }
    
    int getTotalInts() const {
        return totalInts;
    }
    
    void Destructor() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
