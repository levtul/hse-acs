#ifndef __functional__
#define __functional__

//------------------------------------------------------------------------------
// functional.h - содержит описание прямоугольника  и его интерфейса
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
using namespace std;

struct functional {
    enum typing {
        STRICT, DYNAMIC
    };
    typing typing_type;
    bool lazy_coputation;
    // общие характеристики
    double popularity;
    int creation_year;
    char name[50];
};

void In(functional &lang, FILE* file);

void InRnd(functional &lang);

void Out(functional &lang, FILE* file);

void OutForTestGen(functional &lang, FILE* file);

double CompareValue(functional &lang);




#endif
