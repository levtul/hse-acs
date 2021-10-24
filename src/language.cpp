//------------------------------------------------------------------------------
// language.cpp - содержит процедуры связанные с обработкой обобщенного языка
// и создания произвольного языка
//------------------------------------------------------------------------------

#include "language.h"
#include "functional.h"
#include "object_oriented.h"
#include "procedural.h"

language *language::StaticIn(std::ifstream &ifst) {
  std::string type, tmp;
  ifst >> type >> tmp;
  language *sp = nullptr;
  std::string name, creation_year, popularity;
  if (type == "functional") {
    sp = new functional;
  } else if (type == "object_oriented") {
    sp = new object_oriented;
  } else if (type == "procedural") {
    sp = new procedural;
  }
  ifst >> tmp >> name >> tmp >> creation_year >> tmp >> popularity;
  if (sp != nullptr) {
    sp->name = name;
    sp->creation_year = std::stoi(creation_year.c_str());
    sp->popularity = std::stod(popularity.c_str());
    sp->In(ifst);
  }
  return sp;
}
language *language::StaticInRnd() {
  int type = rand() % 3;
  language *sp = nullptr;
  if (type == 0) {
    sp = new functional;
  } else if (type == 1) {
    sp = new object_oriented;
  } else if (type == 2) {
    sp = new procedural;
  }
  int size = rand() % (MAX_NAME_SIZE - 2) + 1;
  for (int i = 0; i < size; i++) {
    sp->name.push_back('a' + rand() % 26);
  }
  sp->creation_year = rand() % 50 + 1970;
  sp->popularity = rand() % 100000 * 0.001;
  sp->InRnd();
  return sp;
}
double language::CompareValue() { return (double)creation_year / name.size(); }
