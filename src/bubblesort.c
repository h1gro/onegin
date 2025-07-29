#include "../include/strsort.h"
#include <string.h>
#include <ctype.h>

void BubbleSort(char** buffer, int len, int (*comparator)(const char*, const char*))
{
    assert(buffer);

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (comparator(buffer[j], buffer[j+1]) > 0)
            {
                printf("SWAPING:\nbefore: str1 = %s, str2 = %s\n", buffer[j], buffer[j+1]);
                StringSwap(&buffer[j], &buffer[j+1]);
                printf("after: str1 = %s, str2 = %s\n\n", buffer[j], buffer[j+1]);
            }
        }
    }
}

int StrCmp(const char* str1, const char* str2)
{
    assert(str1);
    assert(str2);

    printf("str1: %s\nstr2: %s\n", str1, str2);

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
            printf("done compare\n\n");
            return current_status;
        }

        if (str1[first_index] != '\0'){first_index++;}
        if (str1[first_index] != '\0'){second_index++;}
    }

    return EQUAL;
}

compare LinearComparator(char elem1, char elem2)
{
    //printf("<<<elem1 = %c || elem2 = %c>>>\n", tolower(elem1), tolower(elem2));

    if (tolower(elem1) < tolower(elem2))
    {
        printf("%c < %c \n", elem1, elem2);
        return LESS;
    }

    else if (tolower(elem1) > tolower(elem2))
    {
        printf("%c > %c \n", elem1, elem2);
        return MORE;
    }

    return EQUAL;
}

is_empty IsEmpty(const char* str1, const char* str2)
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
