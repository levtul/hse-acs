# Отчет: задание 3
### Тулявко Лев Владимирович, БПИ205
Номер варианта = 190

Yомер задания = 8

Номер функции = 14

---
## Условие
Требуется создать обобщенный класс языка программирования и
три допустимые альтернативы:
* **Функциональный язык:** типизация - строгая/динамическая - 
  перечислимый тип; поддержка «ленивых» вычислений – булевский тип
* **Объектно-ориентированный язык:** наследование - 
  одинарное/множественное/интерфейса – перечислимый тип
* **Процедурный язык:** наличие, отсутствие абстрактных типов данных - 
  булевская величина
  
Общие для всех альтернатив характеристики: популярность в 
процентах(TIOBI) — действительное; год создания — целое; название - строка

Также требуется обработать контейнер с данными следующим образом:
упорядочить элементы контейнера по убыванию используя
сортировку Шелла (Shell Sort). В качестве ключей для сортировки используется
частное от деления года создания на количество символов в
названии - действительное число

---
## Детали реализации

Формат ввода: 
1. Случайно генерируемые данные:
  
   `python3 main.py -n count output-file1 output-file2`

   Пример: task1 -n 3 out1.txt out2.txt

2. Ввод из файла
  
   `python3 main.py -f input-file output-file1 output-file2`

   Пример task1 -f input.txt out1.txt

Формат представления языка:

Пример:

    functional language:
        name: lqjgjchiscylesok
        creation_date: 1971
        popularity: 90.350000
        typing_type: DYNAMIC
        compare_value: 123.000000

Формат ввода и вывода совпадают, это сделано для убоства генерации тестов.

---

## Основные характеристики программы
Число интерфейсных модулей: 0

Число модулей реализации: 6

Общий размер текстов: 6 724 байт $\approx$ 6 Кб

Размер исполняемого кода: не формируется

Время выполнения тестовых файлов: 

```
========== RUNNING TEST 1 ==========
==> Start
==> Finish
Memory: 9940 KB
User time: 0.02 s
Kernel time: 0.00 s
========== RUNNING TEST 2 ==========
==> Start
==> Finish
Memory: 9496 KB
User time: 0.01 s
Kernel time: 0.00 s
========== RUNNING TEST 3 ==========
==> Start
==> Finish
Memory: 9680 KB
User time: 0.01 s
Kernel time: 0.00 s
========== RUNNING TEST 4 ==========
==> Start
==> Finish
Memory: 9652 KB
User time: 0.01 s
Kernel time: 0.00 s
========== RUNNING TEST 5 ==========
==> Start
==> Finish
Memory: 9724 KB
User time: 0.02 s
Kernel time: 0.00 s
========== RUNNING TEST 6 ==========
==> Start
==> Finish
Memory: 9696 KB
User time: 0.01 s
Kernel time: 0.00 s
========== RUNNING TEST 7 ==========
==> Start
==> Finish
Memory: 9768 KB
User time: 0.01 s
Kernel time: 0.00 s
========== RUNNING TEST 8 ==========
==> Start
==> Finish
Memory: 9772 KB
User time: 0.02 s
Kernel time: 0.00 s
========== RUNNING TEST 9 ==========
==> Start
==> Finish
Memory: 9744 KB
User time: 0.02 s
Kernel time: 0.00 s
========== RUNNING TEST 10 ==========
==> Start
==> Finish
Memory: 9620 KB
User time: 0.01 s
Kernel time: 0.00 s
========== RUNNING TEST 11 ==========
==> Start
==> Finish
Memory: 9820 KB
User time: 0.02 s
Kernel time: 0.00 s
========== RUNNING TEST 12 ==========
==> Start
==> Finish
Memory: 9772 KB
User time: 0.02 s
Kernel time: 0.00 s
========== RUNNING TEST 13 ==========
==> Start
==> Finish
Memory: 9784 KB
User time: 0.02 s
Kernel time: 0.00 s
========== RUNNING TEST 14 ==========
==> Start
==> Finish
Memory: 9728 KB
User time: 0.02 s
Kernel time: 0.00 s
========== RUNNING TEST 15 ==========
==> Start
==> Finish
Memory: 9820 KB
User time: 0.02 s
Kernel time: 0.00 s
========== RUNNING TEST 16 ==========
==> Start
==> Finish
Memory: 9816 KB
User time: 0.02 s
Kernel time: 0.00 s
========== RUNNING TEST 17 ==========
==> Start
==> Finish
Memory: 9888 KB
User time: 0.02 s
Kernel time: 0.00 s
========== RUNNING TEST 18 ==========
==> Start
==> Finish
Memory: 9836 KB
User time: 0.01 s
Kernel time: 0.00 s
========== RUNNING TEST 19 ==========
==> Start
==> Finish
Memory: 9696 KB
User time: 0.02 s
Kernel time: 0.00 s
========== RUNNING TEST 20 ==========
==> Start
==> Finish
Memory: 9848 KB
User time: 0.02 s
Kernel time: 0.00 s
========== RUNNING TEST EmptyInput ==========
==> Start
==> Finish
Memory: 9524 KB
User time: 0.02 s
Kernel time: 0.00 s
========== RUNNING TEST MaxElemsCount ==========
==> Start
==> Finish
Memory: 16800 KB
User time: 0.27 s
Kernel time: 0.00 s
```
---
## Архитектура

[Файл](https://github.com/levtul/hse-acs/blob/task3/Описание%20архитектуры.pdf)

---
## Сравнительный аланиз
Использование динамически типизированной ВС позволило еще сильнее уменьшить размер исходных
файлов, на 180% по сравнению с процедурным подходом и на 146% по сравнению с объектно-ориентированным подходом.
Это связано с большей свободной действий при использовании динамически типизируемой ВС а так же большим количеством
встроенных функций языка Python3, которые позволяют сильно уменьшат объем кода(синтаксический сахар + встроенные функции) 
Исполняемый файл не формируется, поэтому сравнение не производится
Время прохождения тестов увеличилось примерно в 4-5 раз в соответствующих тестах, использование памяти стало меньше.
Это связано с бОльшими затратами на работу с объектами и их полями/методами, чем при классической ОО архитектуре, и тем более чем при процедурном подходе(использование хеш таблиц для runtime проверки наличия поля/метода и их последующего вызова)