#include "src/container.h"

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void errMessage1() {
    printf("incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n"
            "  Or:\n"
            "     command -t\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n"
           "  Or:\n"
           "     command -t\n");
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    cout << "Start\n";
    container c;
    if (!strcmp(argv[1], "-f")) {
      ifstream ifst(argv[2]);
      c.In(ifst);
    } else if (!strcmp(argv[1], "-n")) {
      auto size = atoi(argv[2]);
      if ((size < 1) || (size > 10000)) {
        cout << "incorrect number of languages = " << size
             << ". Set 0 < number <= 10000\n";
        return 3;
      }
      // системные часы в качестве инициализатора
      srand(static_cast<unsigned int>(time(0)));
      // Заполнение контейнера генератором случайных чисел
      c.InRnd(size);
    } else {
      errMessage2();
      return 2;
    }

    // Вывод содержимого контейнера в файл
    ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    c.Out(ofst1);

    // The 2nd part of task
    ofstream ofst2(argv[4]);
    c.ShellSort();
    c.Out(ofst2);

    cout << "Stop" << endl;
    return 0;
}