# Отчет: задание 2
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
  
   `command -n count output-file1 output-file2`

   Пример: task1 -n 3 out1.txt out2.txt

2. Ввод из файла
  
   `command -f input-file output-file1 output-file2`

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
Число интерфейсных модулей: 6

Число модулей реализации: 5

Общий размер текстов: 16546 байт $\approx$ 16 Кб

Размер исполняемого кода: 271224 байт $\approx$ 264 Кб

Время выполнения тестовых файлов: 

```
========== RUNNING TEST 1 ==========
Start
Stop
Memory: 17024 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 2 ==========
Start
Stop
Memory: 16812 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 3 ==========
Start
Stop
Memory: 16560 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 4 ==========
Start
Stop
Memory: 16716 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 5 ==========
Start
Stop
Memory: 15264 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 6 ==========
Start
Stop
Memory: 14864 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 7 ==========
Start
Stop
Memory: 17132 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 8 ==========
Start
Stop
Memory: 15264 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 9 ==========
Start
Stop
Memory: 14900 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 10 ==========
Start
Stop
Memory: 15052 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 11 ==========
Start
Stop
Memory: 17028 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 12 ==========
Start
Stop
Memory: 17100 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 13 ==========
Start
Stop
Memory: 17196 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 14 ==========
Start
Stop
Memory: 15312 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 15 ==========
Start
Stop
Memory: 17152 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 16 ==========
Start
Stop
Memory: 16740 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 17 ==========
Start
Stop
Memory: 15000 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 18 ==========
Start
Stop
Memory: 15276 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 19 ==========
Start
Stop
Memory: 17168 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 20 ==========
Start
Stop
Memory: 15212 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST EmptyInput ==========
Start
Stop
Memory: 14812 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST MaxElemsCount ==========
Start
Stop
Memory: 25872 KB
User time: 0.06 s
Kernel time: 0.00 s
```
---
## Архитектура

[Файл](https://github.com/levtul/hse-acs/blob/task2/Описание%20архитектуры.pdf)

---
## Сравнительный аланиз
Применение объектно-ориентированного подхода позволило уменьшить размер исходных
файлов на 15%, хотя при этом размер исполняемого файла увеличился более чем вдвое.
Время прохождения тестов поменялось незначительно, использование памяти стало меньше, из-за того что применялось меньше указателей.