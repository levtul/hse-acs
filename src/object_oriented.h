#ifndef __object_oriented__
#define __object_oriented__

//------------------------------------------------------------------------------
// functional.h - содержит описание прямоугольника  и его интерфейса
//------------------------------------------------------------------------------

#include "constants.h"
#include <stdio.h>
#include <stdlib.h>

struct object_oriented {
    enum inheritance {
        SINGLE, 
        MULTIPLE, 
        INTERFACE
    };
    inheritance inheritance_type;
    // общие характеристики
    double popularity;
    int creation_year;
    char name[MAX_NAME_SIZE];
};

void In(object_oriented &lang, FILE* file);

void InRnd(object_oriented &lang);

void Out(object_oriented &lang, FILE* file);

void OutForTestGen(object_oriented &lang, FILE* file);

double CompareValue(object_oriented &lang);

#endif
