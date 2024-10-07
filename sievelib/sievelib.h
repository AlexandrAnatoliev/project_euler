// sievelib.h - static library for вычисления простого числа с помощью решета эратосфена

#ifndef SIEVE
#define SIEVE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct sieve	// структрура "решето"
{
	int len_arr;		// длина массива
	int past_prime;		// значение последнего простого числа в массиве
						// до него статус чисел определен:
						//		0 - простое
						//		1 - составное
						// после - нет	
	char arr[];			// массив составных (1) и простых (0) чисел ! писать обязательно в конце структуры
} sieve_t;

sieve_t* sieve_init_malloc(int max_num);
// operation:		выделение памяти под структуру "решето" заданного размера
// precondition:	max_num	- максимальное число, хранимое в структуре
// postcondition:	выделяет память, заполняет все поля нулями, возвращает указатель на структуру
//					либо NULL и выводит сообщение об ошибке в случае неудачи

bool sieve_free(sieve_t *sieve);
// operation:		освобождает выделенную под структуру память
// precondition:	принимает указатель на структуру
// postcondition:	возвращает true в случае успеха

bool sieve_push_prime(sieve_t *sieve);
// operation:		вносит простое число в структуру, отмечает все составные до конца массива
// precondition:	sieve	- указатель на структуру
// postcondition:	возвращает true, если все удачно
//					false и сообщение об ошибке иначе

int sieve_get_next_prime(sieve_t *sieve);
// operation:		проходит по массиву и возвращает значение следующего простого числа
// precondition:	sieve	- указатель на структуру "решето" 
// postcondition:	возвращает 0 в случае, если до конца массива простых чисел нет

#endif
