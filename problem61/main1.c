// main1.c - problem 61 (project Euler)
// Цикличные фигурные числа

// К фигурным (многоугольным) числам относятся треугольные, квадратные, пятиугольные, шестиугольные,
// семиугольные и восьмиугольные числа, которые расчитываются по следующим формулам:

// Треугольные	 	P3, n = n(n + 1) / 2	 	1, 3, 6, 10, 15, ...
// Квадратные	 	P4, n = n2	 				1, 4, 9, 16, 25, ...
// Пятиугольные	 	P5, n = n(3n−1) / 2	 		1, 5, 12, 22, 35, ...
// Шестиугольные	P6, n = n(2n−1)	 			1, 6, 15, 28, 45, ...
// Семиугольные	 	P7, n = n(5n−3) / 2	 		1, 7, 18, 34, 55, ...
// Восьмиугольные	P8, n = n(3n−2)	 			1, 8, 21, 40, 65, ...

// Упорядоченное множество из трех четырехзначных чисел : 8128, 2882, 8281,
// обладает тремя интересными свойствами
//
// Множество является цикличным : последние две цифры каждого числа являются первыми двумя цифрами
// следующего(включая последнее и первое числа).
// Каждый тип многоугольника — треугольник(P3, 127 = 8128), квадрат(P4, 91 = 8281)
// и пятиугольник(P5, 44 = 2882) — представлены различными числами данного множества.
// Это — единственное множество четырехзначных чисел, обладающее указанными свойствами.
// Найдите сумму элементов единственного упорядоченного множества из шести цикличных четырехзначных чисел,
// в котором каждый тип многоугольников — треугольник, квадрат, пятиугольник, шестиугольник,
// семиугольник и восьмиугольник — представлены различными числами этого множества.

// #define ENCLOSURE 10
// #define LEN_HASH 2000
#include "hash.h"
#include "funcs1.c"
#include "hash.c"
#include <stdio.h>
#include "arr.h"
#include "arr.c"

int main(void)
{
    // TODO переписать get_next_num чтобы возвращала fig_t?
// инициализируем 6 структур типа hash для хранения списков значений фигурных чисел
    hash_t tr;
    hash_t sq;
    hash_t pent;
    hash_t hex;
    hash_t hept;
    hash_t oct;

// создаем массив из указателей на стуктуры hash arr[hash0, hash1... hash5]
    hash_t *figures[] = {&tr, &sq, &pent, &hex, &hept, &oct};

// в цикле обнуляем поля всех шести структур hash
    for (int name = triangle; name <= octagonal; name++)
        hash_null(figures[name]);

// заполняем все шесть структур значениями фигурных чисел
    fig_t fig;
    for (int name = triangle; name <= octagonal; name++)
    {
        fig.name = name;
        int num = get_near_figure(&fig, 1000);
        while (num < 10000)
        {
            push_num(figures[name], num);
            num = get_next_figure(&fig);
        }
    }

// создаем массив порядка fig_t* fig_list[] и заполняем его NULL
// создаем массив занятости arr[cnt][name]  и заполняем его false
	ARR_INIT	// массив флагов
    	fig_t fig_list[6] = {};                                    // cnt

    int name = triangle;
    int cnt = 0;
    int next;

// инициализируем первое число cnt = 0 name = 0
    fig_list[cnt].value = get_near_num(figures[name], 8256);
    fig_list[cnt].name = name;

    push_flag(arr, cnt, name);	// отмечаем первое число
  while (fig_list[0].value < 10000)
    {
        // последняя ячейка
	    if (cnt == 5)
        {
            if (fig_list[5].value % 100 == fig_list[0].value / 100)
                break;
            else
            {
                fig_list[cnt].value = get_next_num(figures[name], fig_list[cnt].value);
                fig_list[cnt].name = name;
                continue;
            }
        }

// если число первое cnt == 0 или "в диапазонах"
// "ищем следующее число" 1200
if(cnt == 0 || ((fig_list[cnt].value < (SHIFT_DIGITS(fig_list[cnt - 1].value) + 100)))
	next = SHIFT_DIGITS(fig_list[cnt].value);	
	
// TODO обработать окончание на 00 - 09
// TODO двигать число вправо
	
// перебираем name от 0
// fl = false
// получаем значения чисел[name]
// если не выходит за пределы диапазона 100 и не заканчивается на 00 - 09
// fl = true нашлось число
// заносим число  fig_list[cnt + 1]
// ставим флаг
// cnt++
// break
//
// если fl == true - нашлось число 
// continue

bool is_num = false;
for(int name = triangle; name <= octagonal; name++)
{
	if(arr[cnt][name] == false)
	{	
                int value = get_near_num(figures[name], next);
		if(value < 


            cnt--;			// переходим влево
	    fig_list[cnt].value = get_next_num(figures[fig_list[cnt].name], fig_list[cnt].value);
           // fig_list->value = get_near_num(figures[name], fig_list[cnt].value);
            continue;
        }

        int next_num = SHIFT_DIGITS(fig_list[cnt].value);
        if(next_num < 1000)	// только четырехзначные числа
	{
		fig_list[cnt].value = get_next_num(figures[fig_list[cnt].name], fig_list[cnt].value);
		continue;
	}

	bool flag = false;	// флаг движения вправо
	cnt++; // идем вправо
        for (int name = triangle; name <= octagonal; name++)
        {



		if(arr[cnt][name] == false)	
            //if (flags[name] == false)
	    


            {
                fig_list[cnt].value = get_near_num(figures[name], next_num);
                fig_list[cnt].name = name;
                flags[name] = true;



		push_flag(arr, cnt, name);



		flag = true;
               // cnt++;
                break;
            }
        }
	if(flag)
		continue;

	del_flag(arr, name, cnt);
        cnt--; // идем влево

        fig_list[cnt].value = get_next_num(figures[fig_list[cnt].name], fig_list[cnt].value);
        continue;
    }

    return 0;
}

// инициализируем 6 структур типа hash для хранения списков значений фигурных чисел
// создаем массив из указателей на стуктуры hash arr[hash0, hash1... hash5]
// в цикле обнуляем поля всех шести структур hash
//
// заполняем все шесть структур значениями фигурных чисел
// вычисляем первое число (1234) и заносим его в хеш
// перебираем числа до 9999 и заносим в хеш
// и так для всех шести структур

// создаем массив порядка fig_t* fig_list[] и заполняем его NULL
// создаем массив занятости arr[cnt][name]  и заполняем его false

// инициализируем первое число cnt = 0 name = 0
// cnt = 0
// cnt_arr[cnt] = ближайшее к 1000 hash_arr[ptr] 1234
// ставим флаг
//
//
// пока fig_list[0].value < 10000
//
// если cnt = 5 (последнее число)
// проверяем соответствие цифр с первым cnt = 0
// если совпало break
// TODO (flag is_answer?)
// иначе - увеличиваем число и continue
//
// если число первое cnt == 0 или "в диапазонах"
// "ищем следующее число" 1200
//
// перебираем name от 0
// fl = false
// получаем значения чисел[name]
// если не выходит за пределы диапазона 100 и не заканчивается на 00 - 09
// fl = true нашлось число
// заносим число  fig_list[cnt + 1]
// ставим флаг
// cnt++
// break
//
// если fl == true - нашлось число 
// continue
//
// "перебираем предыдущее"
// если ничего не нашлось fl == false и число не первое 
// перебираем предыдущее число [cnt] от name до 6
// сравниваем с диапазоном cnt - 1
// если нашлось и 
// снимаем флаг [cnt]
// ставим новый флаг
// break
// continue
//
// "если не нашлось"
// "увеличиваем число"
// обновляем fig_list[cnt]
// continue
//
// иначе если "не в диапазоне"
// если первое - увеличиваем его
// если не первое - обнуляем fig_list[cnt]
// снимаем флаг
// cnt--
//
// continue
//

// освободить память в всех шести структурах hash в цикле
