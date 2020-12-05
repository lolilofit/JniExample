
#include <afxres.h>
#include <cpuid.h>
#include "Main.h"

int getNumbersCount(int i) {
    int cnt = 0;
    while(i > 0) {
        i = i / 10;
        cnt++;
    }
    return cnt;
}

JNIEXPORT jstring JNICALL Java_Main_getInfo(JNIEnv *env, jobject thisObj) {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    int cores_number = sysInfo.dwNumberOfProcessors;

    int CPUInfo[4] = {-1};
    char CPUBrandString[0x40];
    __cpuid(0x80000000, CPUInfo[0], CPUInfo[1], CPUInfo[2], CPUInfo[3]);
    unsigned int nExIds = CPUInfo[0];

    memset(CPUBrandString, 0, sizeof(CPUBrandString));

    for (unsigned int i = 0x80000000; i <= nExIds; ++i)
    {
        __cpuid(i, CPUInfo[0], CPUInfo[1], CPUInfo[2], CPUInfo[3]);

        if (i == 0x80000002)
            memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
        else if (i == 0x80000003)
            memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
        else if (i == 0x80000004)
            memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
    }

    unsigned int size = getNumbersCount(cores_number) + sizeof(CPUBrandString) + 2;
    char res[size];
    sprintf(res, "%d:%s", cores_number, CPUBrandString);
    res[size - 1] = '\0';

    return (*env)->NewStringUTF(env, res);
}
