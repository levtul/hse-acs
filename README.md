# Отчет: задание 4
### Тулявко Лев Владимирович, БПИ205
Номер варианта = 190

Номер задания = 8

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
  
   `task4 -n count output-file1 output-file2`

   Пример: task4 -n 3 out1.txt out2.txt

2. Ввод из файла
  
   `task4 -f input-file output-file1 output-file2`

   Пример task4 -f input.txt out1.txt

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
Число интерфейсных модулей: 2

Число модулей реализации: 6

Общий размер текстов: 19015 байт $\approx$ 19 Кб

Размер исполняемого кода: 103376 байт $\approx$ 104 Кб

Время выполнения тестовых файлов: 

```
========== RUNNING TEST 1 ==========
Start
Stop
Memory: 2148 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 2 ==========
Start
Stop
Memory: 2180 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 3 ==========
Start
Stop
Memory: 2148 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 4 ==========
Start
Stop
Memory: 2196 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 5 ==========
Start
Stop
Memory: 2180 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 6 ==========
Start
Stop
Memory: 2140 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 7 ==========
Start
Stop
Memory: 2148 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 8 ==========
Start
Stop
Memory: 2200 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 9 ==========
Start
Stop
Memory: 2196 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 10 ==========
Start
Stop
Memory: 2144 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 11 ==========
Start
Stop
Memory: 2168 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 12 ==========
Start
Stop
Memory: 2180 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 13 ==========
Start
Stop
Memory: 2192 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 14 ==========
Start
Stop
Memory: 2180 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 15 ==========
Start
Stop
Memory: 2196 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 16 ==========
Start
Stop
Memory: 2192 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 17 ==========
Start
Stop
Memory: 2148 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 18 ==========
Start
Stop
Memory: 2100 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 19 ==========
Start
Stop
Memory: 2140 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST 20 ==========
Start
Stop
Memory: 2184 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST EmptyInput ==========
Start
Stop
Memory: 2132 KB
User time: 0.00 s
Kernel time: 0.00 s
========== RUNNING TEST MaxElemsCount ==========
Start
Stop
Memory: 2144 KB
User time: 0.02 s
Kernel time: 0.01 s
--- Testing finished ---  
```
---
## Сравнительный анализ
В данной работе я использовал ассемблер nasm для наиболее ресурсоемких частей задания(сортировка, и функция, по которой сортируем), и время выполнения уменьшилось более чем в 3 раза относительно решения на C++(которое было самым быстрым из всех прошлых реализаций), и значительно медленнее чем все остальные. При этом, писать код, и в особенности искать ошибки в нем, было гораздо более времязатратно и тяжело. На мой взгляд, сейчас писать обычные программы на ассемблере не целесообразно, так как время программиста стоит гораздо дороже чем процессорное время(сервера достаточно легко расширяются), но если в программе критически важна производительность, то использовать ассемблер, чтобы улучшить результат в "бутылочных горлышках" может быть весьма эффективным подходом(и как раз это я и сделал в текущей работе). 
