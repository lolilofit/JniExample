#include <stdlib.h>

int getNumbersCount(int i) {
    int cnt = 0;
    while(i > 0) {
        i = i / 10;
        cnt++;
    }
    return cnt;
}

char* getInfo() {
    int size = 2;
    char* res;
    res = (char*)malloc(sizeof(char)*size);
    
    sprintf(res, "%d", 2);

    return res;
}
