#include "procedural.h"
#include <string.h>

// для простоты будем вводить в том же формате что и выводим, чтобы
// было удобно генерировать тесты. 
void procedural::In(std::ifstream &ifst) {
    std::string has_adt, tmp;
    ifst >> tmp >> has_adt;
    this->has_adt = atoi(has_adt.c_str());
}

void procedural::InRnd() {
    this->has_adt = rand() % 2;
}

void procedural::Out(std::ofstream &ofst) {
  char *data = new char[200];
  sprintf(data, "procedural language:\n"
                  "    name: %s\n"
                  "    creation_date: %i\n"
                  "    popularity: %f\n"
                  "    has_adt: %i\n"
                  "    compare_value: %f\n",
            name.c_str(), creation_year, popularity, has_adt, CompareValue());
  ofst << data;
  delete[] data;
}

void procedural::OutForTestGen(std::ofstream &ofst) {
  char *data = new char[200];
  sprintf(data, "procedural language:\n"
                "    name: %s\n"
                "    creation_date: %i\n"
                "    popularity: %f\n"
                "    has_adt: %i\n",
          name.c_str(), creation_year, popularity, has_adt);
  ofst << data;
  delete[] data;
}
