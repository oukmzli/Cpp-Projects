#include "bitwise_operations.h"

int invertBits(int num) { return ~num; }

void Erase(char* bitStr, int* str) {
    *str = invertBits(*str);
    Insert(bitStr, str);
    *str = invertBits(*str);
}
