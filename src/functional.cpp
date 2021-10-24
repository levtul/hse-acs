#include "functional.h"
#include <string.h>

void functional::InRnd() {
  lazy_computation = rand() % 2;
  int typing_type = rand() % 2;
  if (typing_type == functional::DYNAMIC) {
    typing_type = functional::DYNAMIC;
  } else if (typing_type == functional::STRICT) {
    typing_type = functional::STRICT;
  }
}

void functional::OutForTestGen(std::ofstream &ofst) {
  std::string s_typing_type;
  if (typing_type == functional::DYNAMIC) {
    s_typing_type = "DYNAMIC";
  } else if (typing_type == functional::STRICT) {
    s_typing_type = "STRICT";
  }
  char *data = new char[200];
  sprintf(data,
          "functional language:\n"
          "    name: %s\n"
          "    creation_date: %i\n"
          "    popularity: %f\n"
          "    typing_type: %s\n",
          name.c_str(), creation_year, popularity, s_typing_type.c_str());
  ofst << data;
  delete[] data;
}

void functional::In(std::ifstream &ifst) {
  std::string typing_type, tmp;
  ifst >> tmp >> typing_type;
  if (typing_type[0] == 'D') {
    this->typing_type = functional::DYNAMIC;
  } else if (typing_type[0] == 'S') {
    this->typing_type = functional::STRICT;
  } else {
    printf("ERROR: Unknown typing type: %s\n", typing_type.c_str());
  }
}

void functional::Out(std::ofstream &ofst) {
  std::string s_typing_type;
  if (typing_type == functional::DYNAMIC) {
    s_typing_type = "DYNAMIC";
  } else if (typing_type == functional::STRICT) {
    s_typing_type = "STRICT";
  }
  char *data = new char[200];
  sprintf(data,
          "functional language:\n"
          "    name: %s\n"
          "    creation_date: %i\n"
          "    popularity: %f\n"
          "    typing_type: %s\n"
          "    compare_value: %f\n",
          name.c_str(), creation_year, popularity, s_typing_type.c_str(),
          CompareValue());
  ofst << data;
  delete[] data;
}
