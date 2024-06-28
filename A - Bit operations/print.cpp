#include "bitwise_operations.h"

void Print(int str, char* bitStr, int isFirst, int i) {
    if (str == 0) {
        *(bitStr+0) = 'e';
        *(bitStr+1) = 'm';
        *(bitStr+2) = 'p';
        *(bitStr+3) = 't';
        *(bitStr+4) = 'y';
        *(bitStr+5) = '\0';
    } else if (i >= 0) {
        if (str & (1 << i)) {
            if (isFirst) {
                (i & (1 << 4)) ? *(bitStr+0) = '1' : *(bitStr+0) = '0';
                (i & (1 << 3)) ? *(bitStr+1) = '1' : *(bitStr+1) = '0';
                (i & (1 << 2)) ? *(bitStr+2) = '1' : *(bitStr+2) = '0';
                (i & (1 << 1)) ? *(bitStr+3) = '1' : *(bitStr+3) = '0';
                (i & (1 << 0)) ? *(bitStr+4) = '1' : *(bitStr+4) = '0';
                bitStr += 5; isFirst = 0;
            } else {
                *(bitStr+0) = ' ';
                (i & (1 << 4)) ? *(bitStr+1) = '1' : *(bitStr+1) = '0';
                (i & (1 << 3)) ? *(bitStr+2) = '1' : *(bitStr+2) = '0';
                (i & (1 << 2)) ? *(bitStr+3) = '1' : *(bitStr+3) = '0';
                (i & (1 << 1)) ? *(bitStr+4) = '1' : *(bitStr+4) = '0';
                (i & (1 << 0)) ? *(bitStr+5) = '1' : *(bitStr+5) = '0';
                bitStr += 6; isFirst = 0;
            }
        }
        if (i == 0) *bitStr = '\0';
        Print(str, bitStr, isFirst, --i);
    }
}

void Print (int str, char* bitStr) { Print(str, bitStr, 1, 31); }
