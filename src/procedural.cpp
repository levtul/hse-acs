#include "procedural.h"
#include <string.h>

// для простоты будем вводить в том же формате что и выводим, чтобы
// было удобно генерировать тесты. 
void In(procedural &lang, FILE* file) {
    fscanf(file, "    name: %s\n"
                 "    creation_date: %i\n"
                 "    popularity: %f\n"
                 "    has_adt: %i\n",
            &lang.name, &lang.creation_year, &lang.popularity, &lang.has_adt);
}

void InRnd(procedural &lang) {
    int size = rand() % (MAX_NAME_SIZE - 2) + 1;
    for (int i = 0; i < size; i++) {
        lang.name[i] = 'a' + rand() % 26;
    }
    lang.name[size] = '\0';
    lang.creation_year = rand() % 50 + 1970;
    lang.has_adt = rand() % 2;
    lang.popularity = rand() % 100000 * 0.001;
}

void Out(procedural &lang, FILE* file) {
    fprintf(file, "procedural language:\n"
                  "    name: %s\n"
                  "    creation_date: %i\n"
                  "    popularity: %f\n"
                  "    has_adt: %i\n"
                  "    copare_value: %f\n",
            lang.name, lang.creation_year, lang.popularity, lang.has_adt, CompareValue(lang));
}

void OutForTestGen(procedural &lang, FILE* file) {
    fprintf(file, "procedural language:\n"
                  "    name: %s\n"
                  "    creation_date: %i\n"
                  "    popularity: %f\n"
                  "    has_adt: %i\n",
            lang.name, lang.creation_year, lang.popularity, lang.has_adt);
}

double CompareValue(procedural &lang) {
    return lang.creation_year / strlen(lang.name);
}