#include "src/container.h"

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void errMessage1() {
    cout << "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

void errMessage2() {
    cout << "incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if(argc != 5) {
        errMessage1();
        return 1;
    }

    cout << "Start"<< endl;
    container c;
    Init(c);

    FILE *file;
    if(!strcmp(argv[1], "-f")) {
        file = fopen(argv[2], "r");
        In(c, file);
        fclose(file);
    } else if (!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) {
            printf("incorrect numer of figures = %i. Set 0 < number <= 10000\n", size);
            return 3;
        }
        srand(static_cast<unsigned int>(time(0)));
        InRnd(c, size);
    }
    else {
        errMessage2();
        return 2;
    }

    file = fopen(argv[3], "w");
    fprintf(file, "Filled container:\n");
    Out(c, file);
    fclose(file);

    file = fopen(argv[4], "w");
    Out(c, file);
    ShellSort(c);
    Out(c, file);
    fclose(file);
    Clear(c);
    cout << "Stop"<< endl;
    return 0;
}