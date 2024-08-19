#include "arr.h"

bool show_arr(const bool (*arr)[COLUMNS])
{	
	printf("\n");

	for(int row = 0; row < ROWS; row++)
	{
		for(int column = 0; column < COLUMNS; column++)
			printf("%d ", arr[row][column]);

		printf("\n");
	}

	printf("\n");

	return true;
}

bool push_flag(bool (*arr)[COLUMNS], int row, int column)
// операция:	включение флага в массиве
// 		одновременно отмечаются как "занятые" нижлежайшие значения
//
// 		0 0 0 0 0 0
// 		0 0 0 0 0 0
// 		0 0 0 0 0 0
// 		0 0 0 0 0 0
// 		0 0 0 0 0 0
// 		0 0 0 0 0 0
//
// 		push_flag(arr, 2, 3);
//
// 		0 0 0 0 0 0
// 		0 0 0 0 0 0
// 		0 0 0 1 0 0
// 		0 0 0 1 0 0
// 		0 0 0 1 0 0
// 		0 0 0 1 0 0
//
// предусловие:	arr	- указатель на инициализированный массив
// 		row	- ряд
// 		column	- столбец
// постусловие: отмечаются флаги в массиве
// 		возвращается true
{
	if((row >= ROWS) || (column >= COLUMNS))
	{
		printf("\nВыход за пределы массива\n");
		return false;
	}

	for(int r = row; r < ROWS; r++)
		arr[r][column] = true;

	return true;
}

bool del_flag(bool (*arr)[COLUMNS], int row, int column)
// операция:	удаление флага из  массива
// 		одновременно отмечаются как "свободные" нижлежайшие значения
//
// 		0 0 0 0 0 0
// 		0 1 0 0 0 0
// 		0 1 1 1 1 0
// 		0 1 1 1 1 0
// 		0 1 1 1 1 0
// 		0 1 1 1 1 0
//
// 		del_flag(arr, 2, 3);
//
// 		0 0 0 0 0 0
// 		0 1 0 0 0 0
// 		0 1 1 0 1 0
// 		0 1 1 0 1 0
// 		0 1 1 0 1 0
// 		0 1 1 0 1 0
//
// предусловие:	arr	- указатель на инициализированный массив
// 		row	- ряд
// 		column	- столбец
// постусловие: выключаются флаги в массиве
// 		возвращается true
// 		возвращается true
{
	if((row >= ROWS) || (column >= COLUMNS))
	{
		printf("\nВыход за пределы массива\n");
		return false;
	}

	for(int r = row; r < ROWS; r++)
		arr[r][column] = false;

	return true;
}
