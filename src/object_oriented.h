#ifndef __object_oriented__
#define __object_oriented__

//------------------------------------------------------------------------------
// object_oriented.h - содержит описание прямоугольника  и его интерфейса
//------------------------------------------------------------------------------

#include "constants.h"
#include "language.h"
#include <fstream>

class object_oriented : public language {
  ~object_oriented() override = default;
  void In(std::ifstream &ifst) override;
  void InRnd() override;
  void Out(std::ofstream &ofst) override;
  void OutForTestGen(std::ofstream &ofst) override;
private:
    enum inheritance {
        SINGLE, 
        MULTIPLE, 
        INTERFACE
    };
    inheritance inheritance_type;
};

#endif
