#include "generator.h"

void GenerateTests(int count) {
    printf("--- Test generation started ---\n");
    
    FILE *file;
    char filename[30];
    for (int i = 1; i <= count; i++) {
        srand(static_cast<unsigned int>(time(0)));
        sprintf(filename, "tests/test%i.txt", i);
        printf("--- Creating test located at %s ---\n", filename);
        container c;
        Init(c);
        InRnd(c, rand() % (i + 10) + (i - 1)*10);
        file = fopen(filename, "w");
        OutForTestGen(c, file);
        fclose(file);
        ShellSort(c);
        sprintf(filename, "test_results/answer%i.txt", i);
        file = fopen(filename, "w");
        Out(c, file);
        fclose(file);
        Clear(c);
    }
    printf("--- Test generation finished ---\n");
}