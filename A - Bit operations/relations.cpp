#include "bitwise_operations.h"

bool LessThen(int a, int b) {
    if (Cardinality(a) == Cardinality(b)) return a < b;
    return Cardinality(a) < Cardinality(b);
}

bool LessEqual(int a, int b) {
    if (Cardinality(a) == Cardinality(b)) return a <= b;
    return Cardinality(a) < Cardinality(b);
}

bool GreatEqual(int a, int b) {
    if (Cardinality(a) == Cardinality(b)) return a >= b;
    return Cardinality(a) > Cardinality(b);
}

bool GreatThen(int a, int b) {
    if (Cardinality(a) == Cardinality(b)) return a > b;
    return Cardinality(a) > Cardinality(b);
}
