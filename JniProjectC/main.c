#include <stdlib.h>
#include "polyglot.h"

int getNumbersCount(int i) {
    int cnt = 0;
    while(i > 0) {
        i = i / 10;
        cnt++;
    }
    return cnt;
}

void* getInfo() {
    int size = 2;
    char* res;
    res = (char*)malloc(sizeof(char)*size);

    sprintf(res, "%d", 2);

    return polyglot_from_string_n(res, size - 1, "utf-8");
}
