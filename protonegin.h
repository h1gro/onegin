#ifndef IFDEF_CONST
#define IFDEF_CONST

#include <stdio.h>
#include <assert.h>

enum Scan_File_Results
{
    FILE_NOT_OPENED = 0,
    FILE_READ = 1,
};

enum Massive_Size
{
    SIZE_I = 5,
    SIZE_J = 37
};

int ScanFile(char onegin[][SIZE_J]);
int MyStrCmp(const char *s1, const char *s2);
int OpenFile(FILE * file);
void StringSwap(int *a, int *b);
void PrintMassive(char onegin[][SIZE_J], int index[]);
void BubbleSort(char onegin[][SIZE_J], int index[]);

#endif
