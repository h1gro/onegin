#include "strsort.h"
#include <string.h>
#include <ctype.h>

void DefineComp(struct file_t* files, const char* comparator)
{
    assert(files);

    //defined what comparator user need by strcmp()
    if (!strcmp(comparator, "length_up"))
    {
        files->comparator = CmpLengthUp;
    }

    else if (!strcmp(comparator, "length_down"))
    {
        files->comparator = CmpLengthDown;
    }

    else if (!strcmp(comparator, "alphabet"))
    {
        #ifdef QSORT_MODE

        files->comparator = CmpAlphabet;

        #else

        files->comparator = StrCmp;

        #endif
    }

    else if (!strcmp(comparator, "alphabet_reverse"))
    {
        files->comparator = CmpAlphabetReverse;
    }

    else
    {
        //error name of comparator
        perror("Comparator did't exist!\n");
        Dtor(files);
        exit(0);
    }
}

void SortText(struct file_t* files)
{
    assert(files);

    #ifdef QSORT_MODE

    qsort(files->addr, files->num_lines, sizeof(char*), files->comparator);

    #else

    BubbleSort(files->addr, files->num_lines, files->comparator);

    #endif
}

void StringSwap (char** a, char** b)
{
    assert(*a);
    assert(*b);

    char* c = *a;
    *a = *b;
    *b = c;
}

//-------------------Comparators------------------------
int CmpAlphabet(const void* str1, const void* str2)
{
    assert(str1);
    assert(str2);

    //type assignment for isalpha() and tolower()
    const char *string1 = *(const char**) str1;
    const char *string2 = *(const char**) str2;

    assert(string1);
    assert(string2);

    /*while we dont get the end of one of the strings we compare their
    symbols (alphabet symbols by func isalpha()) on aski_codes by func tolower()*/
    while ((*string1) && (*string2))
    {
        if ((isalpha(*string1)) && (isalpha(*string2)))
        {
            if (tolower(*string1) != tolower(*string2))
            {
                return tolower(*string1) - tolower(*string2);
            }
        }
        /*increase pointers to compare next symbols of string if
        previous was the same*/
        string1++;
        string2++;
    }

    return 0;
}

#ifdef QSORT_MODE

int CmpAlphabetReverse(const void* str1, const void* str2)
{
    return (-1) * CmpAlphabet(str1, str2);
}

int CmpLengthUp(const void* str1, const void* str2)
{
    /*return difference between two lengths:
    if len(str1) > len(str2) -> return > 0
    if len(str1) = len(str2) -> return = 0
    if len(str1) < len(str2) -> return < 0
    it's exactly the way that comparator of qsort must be*/
    return strlen(*(const char**) str1) - strlen(*(const char**) str2);
}

int CmpLengthDown(const void* str1, const void* str2)
{
    //inverse CmpLengthDown
    return  (-1) * (strlen(*(const char**) str1) - strlen(*(const char**) str2));
}

#else

int CmpAlphabetReverse(const char* str1, const char* str2)
{
    return (-1) * StrCmp(str1, str2);
}

int CmpLengthUp(const char* str1, const char* str2)
{
    /*return difference between two lengths:
    if len(str1) > len(str2) -> return > 0
    if len(str1) = len(str2) -> return = 0
    if len(str1) < len(str2) -> return < 0
    it's exactly the way that comparator of qsort must be*/
    return strlen(*(const char**) str1) - strlen(*(const char**) str2);
}

int CmpLengthDown(const char* str1, const char* str2)
{
    //inverse CmpLengthDown
    return  (-1) * (strlen(*(const char**) str1) - strlen(*(const char**) str2));
}

#endif
