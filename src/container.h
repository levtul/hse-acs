#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "language.h"
#include "constants.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
struct container {
    int len; // текущая длина
    language *cont[MAX_CONTAINER_SIZE];
};

// Инициализация контейнера
void Init(container &c);

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c);

// Ввод содержимого контейнера из указанного потока
void In(container &c, FILE* file);

// Случайный ввод содержимого контейнера
void InRnd(container &c, int size);

// Вывод содержимого контейнера в указанный поток
void Out(container &c, FILE* file);

void OutForTestGen(container &c, FILE* file);

// Сортивка контейнера с помощью сортировки Шелла
void ShellSort(container &c);

#endif