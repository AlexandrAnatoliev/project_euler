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

After each change in the library code, we recompile it:

`./create_static_lib sieve`

... and run the tests:

`./run_tests`
 

## Creating a static library (without using scripts)

All actions are performed in the `sievelib/` directory.

We get the library object file:

`gcc -c ./source/sievelib.c`

The `sievelib.o` file should appear in the `sievelib/` directory.

Create a static library using the **ar** utility:

`ar r libsieve.a sievelib.o`

* `r`           - allows you to insert files into an archive; if there is no archive, then it is created;
* `libsieve.a`  - the name of the archive being created, in GNU/Linux operating systems it must have the prefix **lib** and the extension **.a**;
* `libsieve.o`  - the file from which the archive is created.

The object file can be deleted:

`rm libsieve.o`

The contents of the directory should ultimately contain:
```
libsieve.a  // static library
sievelib.h  // library header file
source/     // folder with the source code of library functions (not needed for work and can be deleted)
```


## Using the library in a program
In this case, we compile files from the `tests/` directory with the library.

All actions are performed in the `sievelib/` directory.

We get the object file from the test file:

`gcc -c tests/push_test.c`

The `sievelib/` directory should contain a `push_test.o` file.

We compile it with the library:

`gcc -o push_test push_test.o -L. -lsieve` 

* `-o push_test`- the `push_test` executable file is compiled;
* `push_test.o` - from an object file;
* `-L.`         - after **-L** we write the path to the library directory (**.** - current directory);
* `-lsieve`     - after **-l**, the library name is written without the **lib** prefix and **.a** suffix.

An `push_test`executable file appears in the `sievelib/` directory and can be runs by the command:

`./push_test`


