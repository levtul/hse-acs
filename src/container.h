#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "constants.h"
#include "language.h"
#include <fstream>

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
class container {
public:
  container();
  ~container();
  // Ввод содержимого контейнера из указанного потока
  void In(std::ifstream &ifst);
  // Случайный ввод содержимого контейнера
  void InRnd(int size);
  // Вывод содержимого контейнера в указанный поток
  void Out(std::ofstream &ofst);
  void OutForTestGen(std::ofstream &ofst);
  void ShellSort();

private:
  void Clear(); // Очистка контейнера от данных
  int len;      // текущая длина
  language *storage[MAX_CONTAINER_SIZE];
};

#endif