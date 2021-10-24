#include "object_oriented.h"
#include <string.h>

// для простоты будем вводить в том же формате что и выводим, чтобы
// было удобно генерировать тесты.
void object_oriented::In(std::ifstream &ifst) {
  std::string inheritance_type, tmp;
  ifst >> tmp >> inheritance_type;
  if (inheritance_type[0] == 'I') {
    this->inheritance_type = object_oriented::INTERFACE;
  } else if (inheritance_type[0] == 'S') {
    this->inheritance_type = object_oriented::SINGLE;
  } else if (inheritance_type[0] == 'M') {
    this->inheritance_type = object_oriented::MULTIPLE;
  } else {
    printf("ERROR: Unknown inheritance type: %s\n", inheritance_type.c_str());
  }
}

void object_oriented::InRnd() {
  int inheritance_type = rand() % 3;
  if (inheritance_type == object_oriented::INTERFACE) {
    this->inheritance_type = object_oriented::INTERFACE;
  } else if (inheritance_type == object_oriented::SINGLE) {
    this->inheritance_type = object_oriented::SINGLE;
  } else if (inheritance_type == object_oriented::MULTIPLE) {
    this->inheritance_type = object_oriented::MULTIPLE;
  }
}

void object_oriented::Out(std::ofstream &ofst) {
  std::string inheritance_type;
  if (this->inheritance_type == object_oriented::INTERFACE) {
    inheritance_type = "INTERFACE";
  } else if (this->inheritance_type == object_oriented::SINGLE) {
    inheritance_type = "SINGLE";
  } else if (this->inheritance_type == object_oriented::MULTIPLE) {
    inheritance_type = "MULTIPLE";
  }
  char *data = new char[200];
  sprintf(data,
          "object_oriented language:\n"
          "    name: %s\n"
          "    creation_date: %i\n"
          "    popularity: %f\n"
          "    inheritance_type: %s\n"
          "    compare_value: %f\n",
          name.c_str(), this->creation_year, this->popularity,
          inheritance_type.c_str(), CompareValue());
  ofst << data;
  delete[] data;
}

void object_oriented::OutForTestGen(std::ofstream &ofst) {
  std::string inheritance_type;
  if (this->inheritance_type == object_oriented::INTERFACE) {
    inheritance_type = "INTERFACE";
  } else if (this->inheritance_type == object_oriented::SINGLE) {
    inheritance_type = "SINGLE";
  } else if (this->inheritance_type == object_oriented::MULTIPLE) {
    inheritance_type = "MULTIPLE";
  }
  char *data = new char[200];
  sprintf(data,
          "object_oriented language:\n"
          "    name: %s\n"
          "    creation_date: %i\n"
          "    popularity: %f\n"
          "    inheritance_type: %s\n"
          "    compare_value: %f\n",
          name.c_str(), this->creation_year, this->popularity,
          inheritance_type.c_str(), CompareValue());
  ofst << data;
  delete[] data;
}


