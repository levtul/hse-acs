//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Конструктор контейнера
container::container() : len{0} {}

//------------------------------------------------------------------------------
// Деструктор контейнера
container::~container() { Clear(); }

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void container::Clear() {
  for (int i = 0; i < len; i++) {
    delete storage[i];
  }
  len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void container::In(std::ifstream &ifst) {
  while (!ifst.eof()) {
    if ((storage[len] = language::StaticIn(ifst)) != nullptr) {
      len++;
    }
  }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void container::InRnd(int size) {
  while (len < size) {
    if ((storage[len] = language::StaticInRnd()) != nullptr) {
      len++;
    }
  }
}

//------------------------------------------------------------------------------
// Output container data.
void container::Out(std::ofstream &ofst) {
  ofst << "Container contains " << len << " elements.\n";
  for (int i = 0; i < len; i++) {
    storage[i]->Out(ofst);
  }
}

void container::OutForTestGen(std::ofstream &ofst) {
  for (int i = 0; i < len; i++) {
    storage[i]->OutForTestGen(ofst);
  }
}

void container::ShellSort() {
  for (int d = len / 2; d > 0; d /= 2) {
    for (int i = d; i < len; i++) {
      for (int j = i; j >= d &&
           storage[j]->CompareValue() < storage[j - d]->CompareValue();
           j -= d) {
        language *tmp;
        tmp = storage[j];
        storage[j] = storage[j - d];
        storage[j - d] = tmp;
      }
    }
  }
}