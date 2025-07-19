#include "strsort.h"
#include <sys/stat.h>

/*suppoted methods of sort: | Cmd of comparators:
1) length for up            |     length_up
2) length for down          |     length_down
3) alphabet                 |     alphabet
4) reverse alphabet         |     alphabet_reverse
*/

int main(int argc, char* argv[])
{
    struct stat unsort_inf = {0}; //init stat struct to get byte-size of the file
    struct file_t files    = {0};

//     char str1[] = "!@#$^&*()_+-";
//     char str2[] = "!@#$^&*()_+-";
//
//     printf("result: %d\n", StrCmp(str1, str2));

//     int buffer[] = {1, 50, 1, -4, 2, 9, 25, 32, 0, 0, 0, 0, 24435, -153, 531, 888, 777, 5678924, 90, 0, 6, -6, 23};
//
//     printf("%d\n\n", buffer[12]);
//
//     BubbleSort(buffer, 23);
//
//     for (int i = 0; i < 23; i++)
//     {
//         printf("%d ", buffer[i]);
//     }
//
//     printf("\n");
//
    ReadArgs(&files, &unsort_inf, argc, argv);

    FilesProcessing(&files, unsort_inf.st_size); //process files (sort.txt and unsort.txt)

    //this function defined what comparator user wrote
    DefineComp(&files, argv[3]);

    BubbleSort(files.addr, files.num_lines);//TODO bublesort works not right!
    //SortText(&files); //qsort

    PrintBuffer(&files); //print sorted version of text in special file

    Dtor(&files); //free up memory and close files
    return 0;
}
