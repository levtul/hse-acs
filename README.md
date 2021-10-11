# Отчет: задание 1
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

Число модулей реализации: 7

Общий размер текстов: 19015 байт $\approx$ 19 Кб

Размер исполняемого кода: 103376 байт $\approx$ 104 Кб

Время выполнения тестовых файлов: 

```
--- Testing started ---
--- Running test tests/test1.txt ---
Test 1: OK. Elements count: 10. Time: 0.0004s
--- Running test tests/test2.txt ---
Test 2: OK. Elements count: 16. Time: 0.0002s
--- Running test tests/test3.txt ---
Test 3: OK. Elements count: 20. Time: 0.0002s
--- Running test tests/test4.txt ---
Test 4: OK. Elements count: 38. Time: 0.0003s
--- Running test tests/test5.txt ---
Test 5: OK. Elements count: 49. Time: 0.0003s
--- Running test tests/test6.txt ---
Test 6: OK. Elements count: 64. Time: 0.0004s
--- Running test tests/test7.txt ---
Test 7: OK. Elements count: 64. Time: 0.0005s
--- Running test tests/test8.txt ---
Test 8: OK. Elements count: 76. Time: 0.0005s
--- Running test tests/test9.txt ---
Test 9: OK. Elements count: 94. Time: 0.0006s
--- Running test tests/test10.txt ---
Test 10: OK. Elements count: 104. Time: 0.0007s
--- Running test tests/test11.txt ---
Test 11: OK. Elements count: 115. Time: 0.0008s
--- Running test tests/test12.txt ---
Test 12: OK. Elements count: 120. Time: 0.0008s
--- Running test tests/test13.txt ---
Test 13: OK. Elements count: 138. Time: 0.0009s
--- Running test tests/test14.txt ---
Test 14: OK. Elements count: 136. Time: 0.0009s
--- Running test tests/test15.txt ---
Test 15: OK. Elements count: 159. Time: 0.0011s
--- Running test tests/test16.txt ---
Test 16: OK. Elements count: 150. Time: 0.0010s
--- Running test tests/test17.txt ---
Test 17: OK. Elements count: 184. Time: 0.0012s
--- Running test tests/test18.txt ---
Test 18: OK. Elements count: 192. Time: 0.0012s
--- Running test tests/test19.txt ---
Test 19: OK. Elements count: 189. Time: 0.0012s
--- Running test tests/test20.txt ---
Test 20: OK. Elements count: 214. Time: 0.0013s
--- Running test tests/testEmptyInput.txt ---
Test EmptyInput: OK. Elements count: 0. Time: 0.0002s
--- Running test tests/testMaxElemsCount.txt ---
Test MaxElemsCount: OK. Elements count: 10000. Time: 0.0634s
--- Testing finished ---  
```
---
## Архитектура

[Файл](https://github.com/levtul/hse-acs/blob/task1/Описание%20архитектуры.pdf)

---
## Сравнительный аланиз
Других заданий еще не было, поэтому сравнивать пока что не с чем