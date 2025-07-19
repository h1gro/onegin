#include "strsort.h"
#include <string.h>
#include <ctype.h>

void DefineComp(struct file_t* files, const char* comparator)
{
    assert(files);

    //defined what comparator user need by strcmp()
    if (!strcmp(comparator, "length_up"))
    {
        files->comparator = CmpLengthUP;
    }

    else if (!strcmp(comparator, "length_down"))
    {
        files->comparator = CmpLengthDown;
    }

    else if (!strcmp(comparator, "alphabet"))
    {
        files->comparator = CmpAlphabet;
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
    //quick sort array of addresses with help of comparator - files->comparator that defined by DefineComp()
    qsort(files->addr, files->num_lines, sizeof(char*), files->comparator);
}

void BubbleSort(char** buffer, int len)
{
    assert(buffer);

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            //TODO think about <, >, = ?
            //ab
            //ac
            if (StrCmp(buffer[i], buffer[i+1]) < 0)
            {
                StringSwap(&buffer[i], &buffer[i+1]);
            }
        }
    }
}

compare StrCmp(char* str1, char* str2)
{
    assert(str1);
    assert(str2);

    int first_index = 0, second_index = 0;

    switch(IsEmpty(str1, str2))
    {
        case FIRST_EMPTY:   return LESS;
                            break;

        case SECOND_EMPTY:  return MORE;
                            break;

        case BOTH_EMPTY:    return EQUAL;
                            break;

        default:            break;
    }

    while ((str1[first_index] != '\0') && (str2[second_index] != '\0'))
    {
        bool str1_id = NOT_ALPHA, str2_id = NOT_ALPHA;

        while (!(str1_id && str2_id))
        {
            // check the current symbol on the first string
            if ((!isalpha(str1[first_index])) && (str1[first_index] != '\0'))
            {
                first_index++;
                str1_id = NOT_ALPHA;
            }

            else
            {
                printf("1{%d}: %c \n", first_index, str1[first_index]);
                str1_id = ALPHA;
            }

            //*//

            // check the current symbol on the second string
            if ((!isalpha(str2[second_index])) && (str2[second_index] != '\0'))
            {
                second_index++;
                str2_id = NOT_ALPHA;
            }

            else
            {
                printf("2{%d}: %c \n", second_index, str2[second_index]);
                str2_id = ALPHA;
            }

        }

        compare current_status = LinearComparator(str1[first_index], str2[second_index]);

        if (current_status != EQUAL)
        {
            return current_status;
        }

        if (str1[first_index] != '\0'){first_index++;}
        if (str1[first_index] != '\0'){second_index++;}
    }

    return EQUAL;
}

compare LinearComparator(char elem1, char elem2)
{
    printf("<<<elem1 = %c || elem2 = %c>>>\n", tolower(elem1), tolower(elem2));

    if (tolower(elem1) < tolower(elem2))
    {
        return LESS;
    }

    else if (tolower(elem1) > tolower(elem2))
    {
        return MORE;
    }

    return EQUAL;
}

is_empty IsEmpty(char* str1, char* str2)
{
    assert(str1);
    assert(str2);

    int empty_id = NOT_EMPTY; //at default we think, that strings are not empty

    if (str1[0] == '\0')
    {
        empty_id += FIRST_EMPTY;
    }

    if (str2[0] == '\0')
    {
        empty_id += SECOND_EMPTY;
    }

    return (is_empty) empty_id;
}

//str1 = ab
//str2 = ac
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

int CmpAlphabetReverse(const void* str1, const void* str2)
{
    return (-1) * CmpAlphabet(str1, str2);
}

int CmpLengthUP(const void* str1, const void* str2)
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
