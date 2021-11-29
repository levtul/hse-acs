#ifndef __data__
#define __data__

//------------------------------------------------------------------------------
// data.h - Описание данных бестиповой программы
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Раздел констант
//------------------------------------------------------------------------------

// Константа, определяющая размер целого числа
int const intSize = sizeof(int);
// Константа, определяющая размер символа
int const charSize = sizeof(char);
// Константа, определяющая размер булевого числа
int const boolSize = sizeof(bool);
// Константа, определяющая размер числа с плавающей точкой
int const doubleSize = sizeof(double);
// Константа, задающая размер для типа перечисления
int const enumSize = intSize;

// Константа, опеределяющая максимальную длину имени языка
int const maxNameSize = 30;
// Константа, опеределяющая максимальный размер имени языка
int const nameSize = maxNameSize * charSize;
// Константа, задающая размер общих характеристик языка
int const commonSize = nameSize + intSize + doubleSize;
// Константа, задающая размер функционального языка
int const functionalSize = commonSize + enumSize;
// Константа, задающая размер процедурного языка
int const proceduralSize = commonSize + boolSize;
// Константа, задающая размер объектно-ориентированного языка
int const objectOrientedSize = commonSize + enumSize;

// Константа, задающая размер для треугольника
int const languageSize = sizeof(int) + (functionalSize >= objectOrientedSize ? (functionalSize >= proceduralSize ? functionalSize : proceduralSize) : (objectOrientedSize >= proceduralSize ? objectOrientedSize : proceduralSize));
// Константа, определяющая размерность массива фигур
int const maxSize = 10000 * languageSize;
// Константа, задающая признак функционального языка
int const FUNCTIONAL = 1;
// Константа, задающая признак процедурного языка
int const PROCEDURAL = 2;
// Константа, задающая признак объектно-ориентированного языка
int const OBJECT_ORIENTED = 3;

//------------------------------------------------------------------------------
// Описание используемых функций
//------------------------------------------------------------------------------

// Ввод содержимого контейнера из указанного файла
void InContainer(void *c, int *len, FILE *ifst);
// Случайный ввод содержимого контейнера
void InRndContainer(void *c, int *len, int size);
// Вывод содержимого контейнера в файл
void OutContainer(void *c, int len, FILE *ofst);
// Вычисление суммы периметров всех фигур в контейнере
void ShellSort(void *c, int len);

#endif
