#include "protonegin.h"

int main() //TODO output in file
{
    char onegin[SIZE_I][SIZE_J] = {};
    int index[SIZE_I] = {};

    for (int i = 0; i < SIZE_I; i++)
    {
        index[i] = i;
    }

    if (ScanFile(onegin) == FILE_READ)
    {
        BubbleSort(onegin, index);
        //printf("> %s", onegin[index[0]]);
        PrintMassive(onegin, index);
    }
    return 0;
}

void PrintMassive(char onegin[][SIZE_J], int index[])
{
    for(int i = 0; i < SIZE_I; i++)
    {
        printf("onegin[%d] = %s\n", i, onegin[index[i]]);  //TODO other func
    }
}

//динамический массив онегин (размер через доп функцию)
//динамический массив указателей (размер через подсчёт \n)
//buffer (поменять в нем все \n на \0)
