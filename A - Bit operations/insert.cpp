#include "bitwise_operations.h"

void Insert(char* bitStr, int* str) {
    if (*bitStr == '\0') return;
    if (*bitStr == ' ') Insert((bitStr + 1), str);
    else if (*bitStr == '0' || *bitStr == '1') {
        int exp = 0;
        *(bitStr+0) == '1' ? exp |= (1 << 4) : exp;
        *(bitStr+1) == '1' ? exp |= (1 << 3) : exp;
        *(bitStr+2) == '1' ? exp |= (1 << 2) : exp;
        *(bitStr+3) == '1' ? exp |= (1 << 1) : exp;
        *(bitStr+4) == '1' ? exp |= (1 << 0) : exp;
        
        *str |= (1 << exp);
        Insert(bitStr + 5, str);
    }
}
