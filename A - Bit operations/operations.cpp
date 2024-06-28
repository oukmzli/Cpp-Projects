#include "bitwise_operations.h"

void Union(int a, int b, int* c)        { *c = a | b; }
void Intersection(int a, int b, int* c) { *c = a & b; }
void Symmetric(int a, int b, int* c)    { *c = a ^ b; }
void Difference(int a, int b, int* c)   { *c = a & (~b); }
void Complement(int a, int* b)          { *b = (~a); }
