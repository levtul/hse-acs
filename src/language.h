#ifndef __language__
#define __language__

//------------------------------------------------------------------------------
// language.h - содержит описание обобщающего языка программирования,
//------------------------------------------------------------------------------

#include <fstream>
#include <string>

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся языки
class language {
public:
  virtual ~language() {};
  // Ввод обобщенной фигуры
  static language *StaticIn(std::ifstream &ifdt);
  // Ввод обобщенной фигуры
  virtual void In(std::ifstream &ifdt) = 0;
  // Случайный ввод обобщенной фигуры
  static language *StaticInRnd();
  // Виртуальный метод ввода случайной фигуры
  virtual void InRnd() = 0;
  // Вывод обобщенной фигуры
  virtual void Out(std::ofstream &ofst) = 0;
  virtual void OutForTestGen(std::ofstream &ofst) = 0;
  // Вычисление периметра обобщенной фигуры
  double CompareValue();
protected:
  double popularity;
  int creation_year;
  std::string name;
};

#endif
