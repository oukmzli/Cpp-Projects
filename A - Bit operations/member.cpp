#include "bitwise_operations.h"

bool Member(char* element, int str) {
    if(*element == '\0') return 0;
    if(*element == ' ') return Member(element + 1, str);
    else if (*element == '0' || *element == '1') {
        int exp = 0;
        *(element+0) == '1' ? exp |= (1 << 4) : exp;
        *(element+1) == '1' ? exp |= (1 << 3) : exp;
        *(element+2) == '1' ? exp |= (1 << 2) : exp;
        *(element+3) == '1' ? exp |= (1 << 1) : exp;
        *(element+4) == '1' ? exp |= (1 << 0) : exp;
        return str & (1 << exp) ? 1 : 0;
    }
    return 0;
}
