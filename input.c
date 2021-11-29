//------------------------------------------------------------------------------
// input.c - единица компиляции, вбирающая в себя все функции ввода данных
//------------------------------------------------------------------------------

#include <stdio.h>

#include "data.h"
#include "enumerations.h"

// Ввод параметров прямоугольника из файла
void InFunctional(void *f, FILE *ifst) {
    char typing_type[20];
    fscanf(ifst, "    name: %s\n"
                 "    creation_date: %i\n"
                 "    popularity: %lf\n"
                 "    typing_type: %s\n",
            f, f + nameSize, f + nameSize + doubleSize, typing_type);
    int *ptr = (int*)(f + commonSize);
    if (*typing_type == 'D') {
        *ptr = DYNAMIC;
    } else if (*typing_type == 'S') {
        *ptr = STRICT;
    } else {
        printf("ERROR: Unknown typing type: %s\n", typing_type);
    }
}

// Ввод параметров треугольника из файла
void InProcedural(void *p, FILE *ifst) {
    fscanf(ifst, "    name: %s\n"
                 "    creation_date: %i\n"
                 "    popularity: %lf\n"
                 "    has_adt: %i\n",
            p, p + nameSize, p + nameSize + doubleSize, p + commonSize);
}

void InObjectOriented(void *o, FILE *ifst) {
    char inheritance_type[20];
    fscanf(ifst, "    name: %s\n"
                 "    creation_date: %i\n"
                 "    popularity: %lf\n"
                 "    inheritance_type: %s\n",
            o, o + nameSize, o + nameSize + doubleSize, inheritance_type);
    int *ptr = (int*)(o + commonSize);
    if (*inheritance_type == 'I') {
        *ptr = INTERFACE;
    } else if (*inheritance_type == 'S') {
        *ptr = SINGLE;
    } else if (*inheritance_type == 'M') {
        *ptr = MULTIPLE;
    } else {
        printf("ERROR: Unknown typing type: %s\n", inheritance_type);
    }
}

// Ввод параметров обобщенного языка из файла
int InLanguage(void *s, FILE *ifst) {
    char lang_type[20];
    // считываем строку вида "<lang_type> language" и обрасываем второе слово
    fscanf(ifst, "%s%*s\n", lang_type);
    if (*(lang_type) == 'p') {
        *((int*)s) = PROCEDURAL;
        InProcedural(s + intSize, ifst);
        return 1;
    } else if (*(lang_type) == 'f') {
        *((int*)s) = FUNCTIONAL;
        InFunctional(s + intSize, ifst);
        return 1;
    } else if (*(lang_type) == 'o') {
        *((int*)s) = OBJECT_ORIENTED;
        InObjectOriented(s + intSize, ifst);
        return 1;
    } else {
        printf("ERROR: unknown language type: %s\n", lang_type);
        return 0;
    }
}

// Ввод содержимого контейнера из указанного файла
void InContainer(void *c, int *len, FILE *ifst) {
    void *tmp = c;
    while(!feof(ifst)) {
        if(InLanguage(tmp, ifst)) {
            tmp = tmp + languageSize;
            (*len)++;
        }
    }
}
