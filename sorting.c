#include "data.h"
#include <string.h>

double CompareValue(void *l) {
    int len = strlen((char*)l);
    return (double) *(int*)(l + nameSize) / len;
}

void ShellSort(void *c, int len) {
    for (int d = len / 2; d > 0; d /= 2) {
        for (int i = d; i < len; i++) {
            for (int j = i; j >= d && CompareValue(c + j * languageSize + intSize) < CompareValue(c + (j - d) * languageSize + intSize); j -= d) {
                void *tmp[languageSize];
                memcpy(tmp, c + j * languageSize, languageSize);
                memcpy(c + j * languageSize, c + (j - d) * (languageSize), languageSize);
                memcpy(c + (j - d) * (languageSize), tmp, languageSize);
            }
        }
    }
}