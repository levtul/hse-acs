#include "src/container.h"

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

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

void runTests() {
    printf("--- Testing started ---\n");
    FILE *file, *ans_file;
    char filename[50];
    char ans_filename[50];
    for (int i = 1; i <= 20; i++) {
        clock_t start = clock();
        sprintf(filename, "tests/test%i.txt", i);
        printf("--- Running test %s ---\n", filename);
        container c;
        Init(c);
        file = fopen(filename, "r");
        In(c, file);
        fclose(file);
        ShellSort(c);
        sprintf(filename, "test_results/testResult%i.txt", i);
        file = fopen(filename, "w");
        Out(c, file);
        fclose(file);
        int length = c.len;
        Clear(c);
        file = fopen(filename, "r");
        sprintf(ans_filename, "test_results/answer%i.txt", i);
        ans_file = fopen(ans_filename, "r");
        int f, s;
        bool failed = false;
        while (true) {
            f = fgetc(file);
            s = fgetc(ans_file);
            if (f != s) {
                printf("Test %i failed\n", i);
                failed = true;
                break;
            } else if (f == EOF) {
                break;
            }
        }
        if (!failed) {
            start = clock() - start;
            double duration = ((float)start)/CLOCKS_PER_SEC;
            printf("Test %i: OK. Elements count: %i. Time: %.4fs\n", i, length, duration);
        }
        fclose(file);
        fclose(ans_file);
    }
    sprintf(filename, "tests/testEmptyInput.txt");
    clock_t start = clock();
    printf("--- Running test %s ---\n", filename);
    container c;
    Init(c);
    file = fopen(filename, "r");
    In(c, file);
    fclose(file);
    ShellSort(c);
    sprintf(filename, "test_results/testResultEmptyInput.txt");
    file = fopen(filename, "w");
    Out(c, file);
    fclose(file);
    Clear(c);
    file = fopen(filename, "r");
    sprintf(ans_filename, "test_results/answerEmptyInput.txt");
    ans_file = fopen(ans_filename, "r");
    int f, s;
    bool failed = false;
    while (true) {
        f = fgetc(file);
        s = fgetc(ans_file);
        if (f != s) {
            printf("Test EmptyInput failed\n");
            failed = true;
            break;
        } else if (f == EOF) {
            break;
        }
    }
    if (!failed) {
        start = clock() - start;
        double duration = ((float)start)/CLOCKS_PER_SEC;
        printf("Test EmptyInput: OK. Elements count: 0. Time: %.4fs\n", duration);
    }
    fclose(file);
    fclose(ans_file);
    sprintf(filename, "tests/testMaxElemsCount.txt");
    start = clock();
    printf("--- Running test %s ---\n", filename);
    container c1;
    Init(c1);
    file = fopen(filename, "r");
    In(c1, file);
    fclose(file);
    ShellSort(c1);
    sprintf(filename, "test_results/testResultMaxElemsCount.txt");
    file = fopen(filename, "w");
    Out(c1, file);
    fclose(file);
    Clear(c1);
    file = fopen(filename, "r");
    sprintf(ans_filename, "test_results/answerMaxElemsCount.txt");
    ans_file = fopen(ans_filename, "r");
    failed = false;
    while (true) {
        f = fgetc(file);
        s = fgetc(ans_file);
        if (f != s) {
            printf("Test answerMaxElemsCount failed\n");
            failed = true;
            break;
        } else if (f == EOF) {
            break;
        }
    }
    if (!failed) {
        start = clock() - start;
        double duration = ((float)start)/CLOCKS_PER_SEC;
        printf("Test MaxElemsCount: OK. Elements count: 10000. Time: %.4fs\n", duration);
    }
    fclose(file);
    fclose(ans_file);
    printf("--- Testing finished ---\n");
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if (argv[1][1] == 't') {
        runTests();
        return 0;
    } else if (argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start\n");
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
    ShellSort(c);
    Out(c, file);
    fclose(file);
    Clear(c);
    printf("Stop\n");
    return 0;
}