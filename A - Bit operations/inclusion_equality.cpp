#include "bitwise_operations.h"

bool Inclusion(int a, int b) { return (a & b) == a ? 1 : 0; }
bool Equality(int a, int b) { return a == b ? 1 : 0; }
