//------------------------------------------------------------------------------
// language.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#include "language.h"
#include "functional.h"
#include "procedural.h"
#include "object_oriented.h"
#include <string.h>

enum key {FUNCTIONAL, PROCEDURAL, OBJECT_ORIENTED};

//------------------------------------------------------------------------------
language *In(FILE* file) {
    char lang_type[20];
    // считываем строку вида "<lang_type> language" и обрасываем второе слово
    fscanf(file, "%s%*s\n", lang_type);
    language *lang = new language;
    if (*(lang_type) == 'p') {
        lang->k = language::PROCEDURAL;
        In(lang->p, file);
    } else if (*(lang_type) == 'f') {
        lang->k = language::FUNCTIONAL;
        In(lang->f, file);
    } else if (*(lang_type) == 'o') {
        lang->k = language::OBJECT_ORIENTED;
        In(lang->o, file);
    } else {
        delete lang;
        printf("ERROR: unknown language type: %s\n", lang_type);
        return nullptr;
    }
    return lang;
}

language *InRnd() {
    language *lang = new language;
    int lang_type = rand() % 3;
    if (lang_type == PROCEDURAL) {
        lang->k = language::PROCEDURAL;
        InRnd(lang->p);
    } else if (lang_type == FUNCTIONAL) {
        lang->k = language::FUNCTIONAL;
        InRnd(lang->f);
    } else if (lang_type == OBJECT_ORIENTED) {
        lang->k = language::OBJECT_ORIENTED;
        InRnd(lang->o);
    }
    return lang;
}

void Out(language &lang, FILE* file) {
    if (lang.k == language::PROCEDURAL) {
        Out(lang.p, file);
    } else if (lang.k == language::FUNCTIONAL) {
        Out(lang.f, file);
    } else if (lang.k == language::OBJECT_ORIENTED) {
        Out(lang.o, file);
    } else {
        printf("ERROR: incorrect key\n");
    }
}

void OutForTestGen(language &lang, FILE* file) {
    if (lang.k == language::PROCEDURAL) {
        OutForTestGen(lang.p, file);
    } else if (lang.k == language::FUNCTIONAL) {
        OutForTestGen(lang.f, file);
    } else if (lang.k == language::OBJECT_ORIENTED) {
        OutForTestGen(lang.o, file);
    } else {
        printf("ERROR: incorrect key\n");
    }
}

//------------------------------------------------------------------------------
// вычисление значения, по которому будем сортировать, в нашем случае
// частное от деления деления года создания на количество символов в названии
double CompareValue(language &lang) {
    switch(lang.k) {
        case FUNCTIONAL:
            return CompareValue(lang.f);
            break;
        case PROCEDURAL:
            return CompareValue(lang.p);
            break;
        case OBJECT_ORIENTED:
            return CompareValue(lang.o);
            break;
        default:
            return 0;
    }
}



