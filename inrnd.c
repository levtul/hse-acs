#include <stdlib.h>

#include "data.h"

void InRndFunctional(void *f) {
    int typing_type = rand() % 2 + 1;
    if (typing_type == DYNAMIC) {
        *(int*)(f + commonSize) = DYNAMIC;
    } else if (typing_type == STRICT) {
        *(int*)(f + commonSize) = STRICT;
    }
}

void InRndProcedural(void *p) {
    *(int*)(p + commonSize) = rand() % 2;
}

void InRndObjectOriented(void *o) {
    int inheritance_type = rand() % 3 + 1;
    if (inheritance_type == INTERFACE) {
        *(int*)(o + commonSize) = INTERFACE;
    } else if (inheritance_type == SINGLE) {
        *(int*)(o + commonSize) = SINGLE;
    } else if (inheritance_type == MULTIPLE) {
        *(int*)(o + commonSize) = MULTIPLE;
    }
}

// Случайный ввод языка
int InRndLanguage(void *l) {
    int size = rand() % (maxNameSize - 2) + 1;
    for (int i = 0; i < size; i++) {
        *(char*)(l + intSize + i) = 'a' + rand() % 26;
    }
    *(char*)(l + intSize + size) = '\0';
    *(int*)(l + intSize + nameSize) = rand() % 50 + 1970;
    *(double*)(l + intSize + nameSize + intSize) = rand() % 100000 * 0.001;
    int k = rand() % 3 + 1;
    if (k == PROCEDURAL) {
        *((int*)l) = PROCEDURAL;
        InRndProcedural(l + intSize);
        return 1;
    } else if (k == FUNCTIONAL) {
        *((int*)l) = FUNCTIONAL;
        InRndFunctional(l + intSize);
        return 1;
    } else if (k == OBJECT_ORIENTED) {
        *((int*)l) = OBJECT_ORIENTED;
        InRndObjectOriented(l + intSize);
        return 1;
    } else {
        return 0;
    }
}

// Случайный ввод содержимого контейнера
void InRndContainer(void *c, int *len, int size) {
    void *tmp = c;
    while(*len < size) {
        if(InRndLanguage(tmp)) {
            tmp = tmp + languageSize;
            (*len)++;
        }
    }
}
