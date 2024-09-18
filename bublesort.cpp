#include "protonegin.h"

#include <math.h>
#include <string.h>
#include <ctype.h>

void BubbleSort(char onegin[][SIZE_J], int index[])
{
    for (int j = 0; j < SIZE_I -1; j++)
    {
        for (int i = 0; i < SIZE_I - j; i++)
        {
            int x = MyStrCmp(onegin[index[i]], onegin[index[i+1]]);
            //printf("x: %d\n", x);
            if (x > 0)
            {
                //printf("%d %d,", index[i], index[i+1]);
                StringSwap((index+i), (index + i+1));//(index + i)
                //printf("%d %d\n", index[i], index[i+1]);
            }
        }
    }

}

void StringSwap(int *a, int *b)
{
    int swap = *a;
    *a = *b;
    *b = swap; //TODO read bat
}

int MyStrCmp(const char *s1, const char *s2)
{
    int elem_s1 = 0, elem_s2 = 0;

    while (elem_s1 < SIZE_J && elem_s2 < SIZE_J)
    {
        //if (isupper(s1[elem_s1]) == 0) {s1[elem_s1] = tolower(s1[elem_s1]);}
        //if (isupper(s2[elem_s2]) == 0) {s2[elem_s2] = tolower(s2[elem_s2]);}
        while (!isalpha(s1[elem_s1])){
            //printf("s1 = %s\n", s1[elem_s1]);
            elem_s1++;
        }
        while (!isalpha(s2[elem_s2])){
            //printf("s2 = %s\n", s2[elem_s2]);
            elem_s2++;
        }
        if (tolower(s1[elem_s1]) != tolower(s2[elem_s2]))
        {
            //printf("s1[elem");
            return (tolower(s1[elem_s1]) - tolower(s2[elem_s2]));
        }
        else
        {
            elem_s1++;
            elem_s2++;
        }
    }
}

