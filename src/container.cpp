//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"
#include "language.h"

//------------------------------------------------------------------------------
// Initialization of container.
void Init(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Clear data from container.
void Clear(container &c) {
    for (int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}

//------------------------------------------------------------------------------
// Input container's data.
void In(container &c, FILE *file) {
    while (!feof(file)) {
        if ((c.cont[c.len] = In(file)) != nullptr) {
            c.len++;
        }
    }
}

// Random input to container.
void InRnd(container &c, int size) {
    while (c.len < size) {
        if ((c.cont[c.len] = InRnd()) != 0) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Output container data.
void Out(container &c, FILE *file) {
    fprintf(file, "%s%d%s", "container contains ", c.len, " elements.\n");
    for (int i = 0; i < c.len; i++) {
        Out(*(c.cont[i]), file);
    }
}

void ShellSort(container &c) {
    for (int d = c.len / 2; d > 0; d /= 2) {
        for (int i = d; i < c.len; i++) {
            for (int j = i; j >= d && CompareValue(*c.cont[j]) < CompareValue(*c.cont[j - d]); j -= d) {
                language *tmp;
                tmp = c.cont[j];
                c.cont[j] = c.cont[j - d];
                c.cont[j - d] = tmp;
            }
        }
    }
}