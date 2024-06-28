#include <iostream>
using namespace std;

// ==========================================================
// 2.
template<typename T>
struct Pair {
    T first;
    T second;
};

template<typename T, int N>
class StaticArray {
public:
    Pair<T> array[N];
    
    void set(int i, T first, T second) {
        array[i].first = first;
        array[i].second = second;
    }
    
    Pair<T> get(int i) {
        return array[i];
    }
    
    /*
     sortowanie przez wstawianie (insertion sort) zostalo wybrane ze wzgledu na mala dlugosc tablicy (mniej 256 elementow), efektywnosc tego sortorania w przypadku malych danych.
     insertion sort jest rowniez stabilny, co jest zaleta, gdy pierwsze pole w strukturze moze sie powtarzac (nie wiecej niz cztery razy, co zachowuje porzadek wzgledny tych powtorzen).
     */
    
    void insertionSort() {
        for (int i = 1; i < N; i++) {
            Pair<T> key = array[i];
            int j = i - 1;
            
            while (j >= 0 && array[j].first > key.first) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
    }
    
    void Display() {
        for (int i = 0; i < N; ++i) {
            cout << "(" << get(i).first << ", " << get(i).second << ") ";
        }
        cout << endl;
    }
};

// ==========================================================
// 3.
struct StringDoublePair {
    string first;
    double second;
};

template<int N>
class StaticArray<StringDoublePair, N> {
public:
    StringDoublePair array[N];
    
    void set(int index, const string& first, double second) {
        if (index >= 0 && index < N) {
            array[index].first = first;
            array[index].second = second;
        }
    }
    
    StringDoublePair get(int index) const {
        if (index >= 0 && index < N) {
            return array[index];
        }
        return StringDoublePair{};
    }
    
    void insertionSort() {
        for (int i = 1; i < N; ++i) {
            StringDoublePair key = array[i];
            int j = i - 1;
            while (j >= 0 && array[j].first > key.first) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
    }
    
    void Display() const {
        for (int i = 0; i < N; ++i) {
            StringDoublePair pair = get(i);
            cout << "(" << pair.first << ", " << pair.second << ") ";
        }
        cout << endl;
    }
};

// ==========================================================
// 4.
template<typename T, int N>
class TwoStacks {
private:
    T data[N];
    int topF;
    int topS;
    
public:
    TwoStacks() {
        topF = -1;
        topS = N;
    }
    
    // Stos pierwszy
    void push1(const T& value) {
        if (topF < topS - 1) {
            data[++topF] = value;
        }
    }
    
    T pop1() {
        if (topF >= 0) {
            return data[topF--];
        }
        return NULL;
    }
    
    T top1() const {
        if (topF >= 0) {
            return data[topF];
        }
        return NULL;
    }
    
    bool empty1() const {
        return topF == -1;
    }
    
    bool full1() const {
        return topF == topS - 1;
    }
    
    // Stos drugi
    void push2(const T& value) {
        if (topS > topF + 1) {
            data[--topS] = value;
        }
    }
    
    T pop2() {
        if (topS < N) {
            return data[topS++];
        }
        return NULL;
    }
    
    T top2() const {
        if (topS < N) {
            return data[topS];
        }
        return NULL;
    }
    
    bool empty2() const {
        return topS == N;
    }
    
    bool full2() const {
        return topS == topF + 1;
    }
};

int main() {
    cout << "2. " << endl;
    StaticArray<int, 5> array;
    array.set(0, 10, 20);
    array.set(1, 5, 15);
    array.set(2, 10, 25);
    array.set(3, 5, 30);
    array.set(4, 1, 5);
    
    array.Display();
    array.insertionSort();
    array.Display();
    
    cout << "\n3. " << endl;
    StaticArray<StringDoublePair, 3> array2;
    array2.set(0, "apple", 2.5);
    array2.set(1, "orange", 3.1);
    array2.set(2, "banana", 1.7);
    
    array2.Display();
    array2.insertionSort();
    array2.Display();
    
    cout << "\n4. " << endl;
    TwoStacks<int, 10> stacks;
    stacks.push1(1);
    stacks.push1(2);
    stacks.push1(3);
    stacks.push2(10);
    stacks.push2(9);
    stacks.push2(8);
    
    cout << "Top1: " << stacks.top1() << endl;
    cout << "Top2: " << stacks.top2() << endl;
    
    while (!stacks.empty1()) {
        cout << "Pop1: " << stacks.pop1() << endl;
    }
    
    while (!stacks.empty2()) {
        cout << "Pop2: " << stacks.pop2() << endl;
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
