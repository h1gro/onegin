#include "protonegin.h"

#include <string.h>
#include <sys\stat.h>

int ScanFile(char onegin[][SIZE_J])
{
    struct stat inf_onegin = {};
    stat("onegin.txt", &inf_onegin);
    long int onegin_size = inf_onegin.st_size;
    printf("%ld\n", onegin_size);
    FILE * file = fopen("onegin.txt", "r") ; //TODO codestyle command string - onegin.txt
    assert(file);
    OpenFile(file);

    for (int i = 0 ; i < SIZE_I; i++)
    {
        fgets(onegin[i], SIZE_J, file);
    }
    fclose(file);
    return FILE_READ;
}

int OpenFile(FILE* file)
{
    if (file == NULL)
    {
        printf("file not opened\n");
        return FILE_NOT_OPENED;
    }
}
