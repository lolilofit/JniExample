#include <stdlib.h>
#include "polyglot.h"
#include <stdio.h>

void* getInfo() {
    FILE* c = popen("grep '^model name\\|^cpu cores' /proc/cpuinfo", "r");
    
    int size = 256;
    char* res;
    res = (char*)malloc(sizeof(char)*size);

    char buf[256];
    int n = 0;

    if(c != NULL) {
	
    	if((n = fread(buf, 1, 255, c)) <= 0) {
		sprintf(res, "error");
	}
	else {
		buf[n] = '\0';
		sprintf(res, "%s", buf);
		
	}
	pclose(c);
    }
    else {
	sprintf(res, "error");
    }
  
    
    return polyglot_from_string_n(res, n, "ascii");
}
