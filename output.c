//------------------------------------------------------------------------------
// output.c - единица компиляции, вбирающая в себя все функции вывода данных
//------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

#include "data.h"
#include "enumerations.h"

void OutFunctional(void *f, FILE *ofst) {
    char *typing_type;
    int* typing = (int*)(f + commonSize);
    if (*typing == DYNAMIC) {
        typing_type = "DYNAMIC";
    } else if (*typing == STRICT) {
        typing_type = "STRICT";
    }
    fprintf(ofst, "functional language:\n"
                  "    name: %s\n"
                  "    creation_date: %i\n"
                  "    popularity: %lf\n"
                  "    typing_type: %s\n"
                  "    compare_value: %lf\n",
            (char*)f, *(int*)(f + nameSize), *(double*)(f + nameSize + intSize), typing_type, CompareValue(f));
}

void OutProcedural(void *p, FILE *ofst) {
     fprintf(ofst, "procedural language:\n"
                  "    name: %s\n"
                  "    creation_date: %i\n"
                  "    popularity: %lf\n"
                  "    has_adt: %i\n"
                  "    compare_value: %lf\n",
            ((char*)p), *(int*)(p + nameSize), *(double*)(p + nameSize + intSize), *(int*)(p + commonSize), CompareValue(p));
}

void OutObjectOriented(void *o, FILE *ofst) {
    char *inheritance_type;
    int* inheritance = (int*)(o + commonSize);
    if (*inheritance == INTERFACE) {
        inheritance_type = "INTERFACE";
    } else if (*inheritance == SINGLE) {
        inheritance_type = "SINGLE";
    } else if (*inheritance == MULTIPLE) {
        inheritance_type = "MULTIPLE";
    }
    fprintf(ofst, "object_oriented language:\n"
                  "    name: %s\n"
                  "    creation_date: %i\n"
                  "    popularity: %lf\n"
                  "    inheritance_type: %s\n"
                  "    compare_value: %lf\n",
            (char*)o, *(int*)(o + nameSize), *(double*)(o + nameSize + intSize), inheritance_type, CompareValue(o));
}

void OutLanguage(void *s, FILE *ofst) {
    int k = *((int*)s);
    if(k == FUNCTIONAL) {
        OutFunctional(s+intSize, ofst);
    } else if (k == PROCEDURAL) {
        OutProcedural(s+intSize, ofst);
    } else if (k == OBJECT_ORIENTED) {
        OutObjectOriented(s+intSize, ofst);
    } else {
        fprintf(ofst, "Incorrect figure!\n");
    }
}

// Вывод содержимого контейнера в файл
void OutContainer(void *c, int len, FILE *ofst) {
    void *tmp = c;
    fprintf(ofst, "Container contains %d elements.\n", len);
    for(int i = 0; i < len; i++) {
        fprintf(ofst, "%d: ", i);
        OutLanguage(tmp, ofst);
        tmp = tmp + languageSize;
    }
}