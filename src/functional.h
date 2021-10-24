#ifndef __functional__
#define __functional__

//------------------------------------------------------------------------------
// functional.h - содержит описание прямоугольника  и его интерфейса
//------------------------------------------------------------------------------

#include "constants.h"
#include "language.h"
#include <fstream>

class functional : public language {
public:
  ~functional() override = default;
  void In(std::ifstream &ifst) override;
  void InRnd() override;
  void Out(std::ofstream &ofst) override;
  void OutForTestGen(std::ofstream &ofst) override;

private:
  enum typing { STRICT, DYNAMIC };
  typing typing_type;
  bool lazy_computation;
};

#endif
