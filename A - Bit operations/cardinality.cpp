#include "bitwise_operations.h"

int Cardinality(int set, int count, int i) {
    set & (1 << i++) ? ++count : count;
    return i < 32 ? Cardinality(set, count, i) : count;
}

int Cardinality(int set) { return Cardinality(set, 0, 0); }
