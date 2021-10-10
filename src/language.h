#ifndef __language__
#define __language__

//------------------------------------------------------------------------------
// language.h - содержит описание обобщающего языка программирования,
//------------------------------------------------------------------------------

#include "functional.h"
#include "procedural.h"
#include "object_oriented.h"
#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся языки
struct language {
    enum key {FUNCTIONAL, PROCEDURAL, OBJECT_ORIENTED};
    key k;
    // используемые альтернативы
    union {
        functional f;
        procedural p;
        object_oriented o;
    };
};

language *In(FILE* file);

language *InRnd();

void Out(language &lang, FILE* file);

void OutForTestGen(language &lang, FILE* file);

double CompareValue(language &lang);

#endif
