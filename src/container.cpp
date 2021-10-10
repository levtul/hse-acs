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
        if ((c.cont[c.len] = In(file)) != 0) {
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
    fprintf(file, "%s%d%s", "container contains ", c.len, " elements.");
    for (int i = 0; i < c.len; i++) {
        fprintf(file, "%s", "\n");
        Out(*(c.cont[i]), file);
    }
}

void ShellSort(container &c) {
    
}