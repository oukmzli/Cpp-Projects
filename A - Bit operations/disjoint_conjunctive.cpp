#include "bitwise_operations.h"

bool Disjoint(int a, int b) { return !(a & b) ? 1 : 0; }
bool Conjunctive(int a, int b) { return (a & b) ? 1 : 0; }
