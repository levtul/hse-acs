#include <string.h>
#include "object_oriented.h"

// для простоты будем вводить в том же формате что и выводим, чтобы
// было удобно генерировать тесты. 
void In(object_oriented &lang, FILE* file) {
    char inheritance_type[20];
    fscanf(file, "    name: %s\n"
                 "    creation_date: %i\n"
                 "    popularity: %lf\n"
                 "    inheritance_type: %s\n",
            lang.name, &lang.creation_year, &lang.popularity, inheritance_type);
    if (*inheritance_type == 'I') {
        lang.inheritance_type = object_oriented::INTERFACE;
    } else if (*inheritance_type == 'S') {
        lang.inheritance_type = object_oriented::SINGLE;
    } else if (*inheritance_type == 'M') {
        lang.inheritance_type = object_oriented::MULTIPLE;
    } else {
        printf("ERROR: Unknown inheritance type: %s\n", inheritance_type);
    }
}

void InRnd(object_oriented &lang) {
    int size = rand() % (MAX_NAME_SIZE - 2) + 1;
    for (int i = 0; i < size; i++) {
        lang.name[i] = 'a' + rand() % 26;
    }
    lang.name[size] = '\0';
    lang.creation_year = rand() % 50 + 1970;
    lang.popularity = rand() % 100000 * 0.001;
    int inheritance_type = rand() % 3;
    if (inheritance_type == object_oriented::INTERFACE) {
        lang.inheritance_type = object_oriented::INTERFACE;
    } else if (inheritance_type == object_oriented::SINGLE) {
        lang.inheritance_type = object_oriented::SINGLE;
    } else if (inheritance_type == object_oriented::MULTIPLE) {
        lang.inheritance_type = object_oriented::MULTIPLE;
    }
}

void Out(object_oriented &lang, FILE* file) {
    char *inheritance_type;
    if (lang.inheritance_type == object_oriented::INTERFACE) {
        inheritance_type = "INTERFACE";
    } else if (lang.inheritance_type == object_oriented::SINGLE) {
        inheritance_type = "SINGLE";
    } else if (lang.inheritance_type == object_oriented::MULTIPLE) {
        inheritance_type = "MULTIPLE";
    }
    fprintf(file, "object_oriented language:\n"
                  "    name: %s\n"
                  "    creation_date: %i\n"
                  "    popularity: %f\n"
                  "    inheritance_type: %s\n"
                  "    compare_value: %f\n",
            lang.name, lang.creation_year, lang.popularity, inheritance_type, CompareValue(lang));
}

void OutForTestGen(object_oriented &lang, FILE* file) {
    char *inheritance_type;
    if (lang.inheritance_type == object_oriented::INTERFACE) {
        inheritance_type = "INTERFACE";
    } else if (lang.inheritance_type == object_oriented::SINGLE) {
        inheritance_type = "SINGLE";
    } else if (lang.inheritance_type == object_oriented::MULTIPLE) {
        inheritance_type = "MULTIPLE";
    }
    fprintf(file, "object_oriented language:\n"
                  "    name: %s\n"
                  "    creation_date: %i\n"
                  "    popularity: %f\n"
                  "    inheritance_type: %s\n",
            lang.name, lang.creation_year, lang.popularity, inheritance_type);
}

double CompareValue(object_oriented &lang) {
    return lang.creation_year / strlen(lang.name);
}