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
    char *lang_type;
    // считываем строку вида "procedural language" и обрасываем второе слово
    fscanf(file, "%s %*s", lang_type); 
    language *lang = new language;
    if (lang_type == "procedural") {
        lang->k = language::PROCEDURAL;
        In(lang->p, file);
    } else if (lang_type == "functional") {
        lang->k = language::FUNCTIONAL;
        In(lang->f, file);
    } else if (lang_type == "object-oriented") {
        lang->k = language::OBJECT_ORIENTED;
        In(lang->o, file);
    } else {
        delete lang;
        char *msg;
        sprintf(msg, "ERROR: unknown language type: %s", lang_type);
        throw runtime_error(msg);
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
        throw runtime_error("ERROR: incorrect key");
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
        throw runtime_error("ERROR: incorrect key");
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



