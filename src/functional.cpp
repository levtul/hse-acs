#include "functional.h"
#include <string.h>

// для простоты будем вводить в том же формате что и выводим, чтобы
// было удобно генерировать тесты. 
void In(functional &lang, FILE* file) {
    char *typing_type;
    fscanf(file, "    name: %s\n"
                 "    creation_date: %i\n"
                 "    popularity: %f\n"
                 "    typing_type: %s\n",
            &lang.name, &lang.creation_year, &lang.popularity, typing_type);
    if (typing_type == "DYNAMIC") {
        lang.typing_type = functional::DYNAMIC;
    } else if (typing_type == "STRICT") {
        lang.typing_type = functional::STRICT;
    } else {
        printf("ERROR: Unknown typing type: %s\n", typing_type);
    }
}

void InRnd(functional &lang) {
    int size = rand() % (MAX_NAME_SIZE - 2) + 1;
    for (int i = 0; i < size; i++) {
        lang.name[i] = 'a' + rand() % 26;
    }
    lang.name[size] = '\0';
    lang.creation_year = rand() % 50 + 1970;
    lang.popularity = rand() % 100000 * 0.001;
    lang.lazy_coputation = rand() % 2;
    int typing_type = rand() % 2;
    if (typing_type == functional::DYNAMIC) {
        lang.typing_type = functional::DYNAMIC;
    } else if (typing_type == functional::STRICT) {
        lang.typing_type = functional::STRICT;
    }
}

void Out(functional &lang, FILE* file) {
    char *typing_type;
    if (lang.typing_type == functional::DYNAMIC) {
        typing_type = "DYNAMIC";
    } else if (lang.typing_type == functional::STRICT) {
        typing_type = "STRICT";
    }
    fprintf(file, "functional language:\n"
                  "    name: %s\n"
                  "    creation_date: %i\n"
                  "    popularity: %f\n"
                  "    typing_type: %s\n"
                  "    compare_value: %f\n",
            lang.name, lang.creation_year, lang.popularity, typing_type, CompareValue(lang));
}

void OutForTestGen(functional &lang, FILE* file) {
    char *typing_type;
    if (lang.typing_type == functional::DYNAMIC) {
        typing_type = "DYNAMIC";
    } else if (lang.typing_type == functional::STRICT) {
        typing_type = "STRICT";
    }
    fprintf(file, "functional language:\n"
                  "    name: %s\n"
                  "    creation_date: %i\n"
                  "    popularity: %f\n"
                  "    typing_type: %s\n",
            lang.name, lang.creation_year, lang.popularity, typing_type);
}

double CompareValue(functional &lang) {
    return lang.creation_year / strlen(lang.name);
}
