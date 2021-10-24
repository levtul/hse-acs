#ifndef __procedural__
#define __procedural__

//------------------------------------------------------------------------------
// procedural.h - содержит описание прямоугольника  и его интерфейса
//------------------------------------------------------------------------------

#include "constants.h"
#include "language.h"
#include <fstream>

struct procedural : public language {
  ~procedural() override = default;
  void In(std::ifstream &ifst) override;
  void InRnd() override;
  void Out(std::ofstream &ofst) override;
  void OutForTestGen(std::ofstream &ofst) override;

private:
  bool has_adt;
};

#endif
