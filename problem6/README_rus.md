# Проект Эйлера, задача 6: Разность между квадратом суммы и суммой квадратов

Для удобства программа разделена на несколько файлов:
* `header.h`        - заголовочный файл, содержащий подключаемые библиотеки и прототипы функций;
* `funcs.c`	        - содержит реализацию функций;
* `main.c`	        - исходный код программы;
* `main`	        - исполняемый файл программы;

Также проект содержит папки:
* `tests/`   - с юнит-тестами функций, использующихся в программе, включает:
    - `test_funcs.h`    - заголовочный файл, содержащий подключаемые для тестирования функции;
    - `test_funcs.c`    - содержит реализацию тестировочных функций;
    - файлы с тестами для каждой функции.
 
* `scripts/` - скрипты для ускорения отладки программы:
    - `main_run`        - собирает, компилирует и запускает файл **main.c** с библиотекой **timerlib**;
    - `compile_and_run` - компилирует и запускает тестовый файл, принимаемый скриптом в качестве аргумента;
    - `run_tests`       - компилирует и запускает тесты функций по списку.

Кроме того, в отдельной папке **timerlib/** находится библиотека **timerlib.h**, служащая для измерения времени работы программы.


## header.h

С помощью конструкции:
```
#ifndef HEADER
#define HEADER
#endif
```
... файл защищен от повторного включения.

Заголовочный файл необходти **<assert.h>** для обработки ошибок.

Файл **"header.h"** cодержит три функции:
* `int get_sq_sum_iter(int)`    - вычисляет квадрат суммы чисел итеративно. Принимает количество натуральных чисел и возвращает квадрат их суммы начисная от 1;
* `int get_sum_sq_iter(int)`    - вычисляет сумму квадратов (итеративная версия);
* `int get_sq_sum_math(int)`    - вычисление квадрата суммы чисел (математическая версия); 
* `int get_sum_sq_math(int)`    - вычисление суммы квадратов (математическая версия).


## timerlib.h - библиотека для измерения времени работы программы
В этом заголовочном файле описаны структуры данных и прототипы (объявления) всех функций, содержащихся в библиотеке.

Заголовочный файл **<time.h>** позволяет работать со временем.

Файл **"timerlib.h"** cодержит три функции:
* `union time_u timer_start()`              - запускает таймер и сохраняет текущее время в объединение **time** (целочисленный тип **clock_t**);
* `union time_u timer_stop(union time_u)`   - останавливает таймер и вычисляет время выполнения программы в секундах, сохраняет в **time** (в вещественном виде - тип **double**);
* `int timer_show(union time_u)`            - выводит время работы на экран, с точностью шесть знаков после запятой.

Объединение типа **union time_u** служит для хранения времени двух разных типов:
* `clock_t` - для измерения времени работы программы;
* `double`  - для вывода результатов работы на экран в вещественном виде.


## main.c

В данном файле расположена функция **main()**, содержащая основную логику программы.

Подключаем стандартные библиотеки и необходимые файлы:
**<stdio.h>**   - библиотека ввода-вывода. Позволяет использовать функцию **printf()**.

Перед началом вычислений запускается таймер **timer_start()**, а по окончании - останавливается **timer_stop()**.

Алгоритм вычислений одинаков для обоих вариантов. Сначала вычисляется квадрат суммы чисел, после чего из него вычистается сумма квадратов.


## test_funcs.h
Содержит объявления функций для тестирования

`bool func_response_is_correct(int, int, int(*func)(int))` - функция проверяет корректность результата, возвращаемого функцией. Принимает ожидаемый результат, значения аргументов проверяемой функции и указатель на нее. Выводит сообщение о корректности / некорректности работы проверяемой функции и возвращает **true** или **false** в зависимости от результатов проверки.


## scripts/
Скрипты для автоматизации отладки программы

### `compile_and_run`
Используется для компиляции и запуска тестовых файлов.

 При вызове принимает имя файла:
`./compile_and_run sum_sq_iter_test.c`

Далее он самостоятельно компилирует его и запускает.

### run_tests
В скрипт записываются тесовые файлы, которые он при запуске компилирует и запускает.
`./run_tests` - запуск скрипта.

### main_run
Собирает файл `main.c` с библиотекой `timerlib`, компилирует и запускает.
Созданный исполняемый файл `main` запускается командой `../main`

### Использование скриптов

После каждого внесения изменений в программу запускаем тесты:
`./run_tests`
 
Если все тесты проходят, перекомпилируем и запускаем программу:
`./main_run`
