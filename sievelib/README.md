# sievelib - static library for calculating prime number using sieve of Eratosthenes

The library consists of two files:
* `libsieve.a`	- object file
* `sievelib.h`	- library header file

The project contains three folders also: 

* `scripts/`- scripts for automating the process of library development and debugging;
    - `create_static_lib`   - script for creating a static library;
    - `file_stat_lib_run`   - script for compiling a file with a static library and running it;
    - `run_tests`           - recompiling test files and running it.

* `sourse/`	- contains a file with the source code of the library functions

* `tests/` 	- tests to check the functionality of the library:
    - `malloc_free_test.c`  - test to check the `sieve_init_malloc()` and `sieve_free()` functions operation;
    - `next_prime_test.c`   - test to check the `sieve_get_next_prime()` functionality; 
    - `push_test.c`         - the `sieve_push_prime()` function test.


## sievelib.h
This header file describes the data structures and prototypes (declarations) of all functions contained in the library.

By means of the design:
```
#ifndef SIEVE
#define SIEVE
#endif
```
... the file is protected from being included again.

The included header files allow you to use the **printf()**, **malloc()**, **assert()** functions and the **bool** type.

The `"timerlib.h"` file contains functions:
* `sieve_t* sieve_init_malloc(int)`     - allocates memory for a **sieve** structure of a given size, fills all fields with zeros, and returns a pointer to the structure;
* `bool sieve_free(sieve_t*)`           - frees the memory allocated for the structure;
* `bool sieve_push_prime(sieve_t*, int)`- adds a prime to the structure, and marks all components until the array's end;
* `int sieve_get_next_prime(sieve_t* )` - returns the value of next prime.


## scripts/
Scripts for automated program debugging.j

### create_static_lib
Used to create a static library.

When called, it takes the library name without specifying the **lib** suffix and the  **.c** file extension (for example, **sievelib.c** is shortened to **sieve**):

`./create_static_lib sieve`

Next, it creates the `libsieve.a` library itself and deletes temporary files.

### file_stat_lib_run
Script to compile a file with a static library and run it.

The script accepts the file being compiles and the library names as arguments. Write the names without the prefix and suffix. For example, `libsieve.a` is shortened to `sieve`, and `test.c` to `test`.

`./file_stat_lib_run test sieve` 

The script recompiles the test file and runs it:

`./test`

... after which it deletes the executable and all temporary files.


### run_tests
The script is used to recompile and run all test files at once. Contains a list of tests to be called.

Runs by the command:
`./run_tests`

### Using scripts

После каждого внесения изменений в код библиотеки, перекомпилируем ее:
`./create_static_lib sieve`

... и запускаем тесты:
`./run_tests`
 

## Создание статической библиотеки (без использования скриптов)

Все действия выполняем в каталоге `sievelib/`.

Получаем объектный файл библиотеки:
`gcc -c ./source/sievelib.c`

В каталоге `sievelib/` должен появиться файл `sievelib.o`.

Создаем статическую библиотеку с помощью утилиты **ar**:
`ar r libsieve.a sievelib.o`
* `r`           - позволяет вставить файлы в архив, если архива нет, то он создается;
* `libsieve.a`  - имя создаваемого архива, в операционных системах GNU/Linux должно иметь префикс **lib** и расширение **.a**;
* `libsieve.o`  - файл из которого создается архив.

Объектный файл можно удалить:
`rm libsieve.o`

Содержимое каталога в итоге должно содержать:
```
libsieve.a  - статическая библиотека
sievelib.h  - заголовочный файл библиотеки
source/     - папка с исходным кодом функций библиотеки (для работы не нужна, можно и удалить)
```


## Использование библиотеки в программе 
В данном случае компилируем с библиотекой файлы из каталога `tests/.

Все действия выполняем в каталоге `sievelib/`.

Получаем объектный файл из тестового файла:
`gcc -c tests/push_test.c`

В каталоге `sievelib/` должен появиться файл `push_test.o`.

Компилируем его с библиотекой:
`gcc -o push_test push_test.o -L. -lsieve` 
* `-o push_test`- компилируется исполняемый файл `push_test`;
* `push_test.o` - из объектного файла;
* `-L.`         - после **-L** пишем адрес каталога, где находится библиотека (**.** - текущий каталог);
* `-lsieve`     - после **-l** пишется имя библиотеки без префикса **lib** и суффикса **.a**.

В каталоге `sievelib` появляется исполняемый файл `push_test`, который можно запустить командой:
`./push_test`


