#ifndef __procedural__
#define __procedural__

//------------------------------------------------------------------------------
// functional.h - содержит описание прямоугольника  и его интерфейса
//------------------------------------------------------------------------------

#include "constants.h"
#include <stdio.h>
#include <stdlib.h>

struct procedural {
    bool has_adt;
    // общие характеристики
    double popularity;
    int creation_year;
    char name[MAX_NAME_SIZE];
};

void In(procedural &lang, FILE* file);

void InRnd(procedural &lang);

void Out(procedural &lang, FILE* file);

void OutForTestGen(procedural &lang, FILE* file);

double CompareValue(procedural &lang);


#endif
