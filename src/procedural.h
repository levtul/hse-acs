#ifndef __procedural__
#define __procedural__

//------------------------------------------------------------------------------
// functional.h - содержит описание прямоугольника  и его интерфейса
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
using namespace std;

struct procedural {
    bool has_adt;
    // общие характеристики
    double popularity;
    int creation_year;
    char name[50];
};

void In(procedural &lang, FILE* file);

void InRnd(procedural &lang);

void Out(procedural &lang, FILE* file);

void OutForTestGen(procedural &lang, FILE* file);

double CompareValue(procedural &lang);


#endif
