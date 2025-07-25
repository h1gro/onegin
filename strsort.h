#ifndef _STR_SORT_
#define _STR_SORT_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct file_t
{
    FILE*  sort;                                 ////pointer on file with sorted text (where must be sorted text)
    FILE*  unsort;                               //pointer on file with unsorted text
    char*  text;                                 //array of the unsorted text
    char** addr;                                 //array of strings adr
    size_t num_lines;                            //counter of lines
    int (*comparator)(const void*, const void*); //name of func comparator
};

//consts for errors of checking file
enum check_file_consts
{
    CHECK_FILE_ERROR = 1,
    CHECK_FILE_OK    = 0,
};

enum compare //like strcmp()
{
    EQUAL = 0,
    MORE  = 1,
    LESS  = -1,
};

enum is_alpha
{
    NOT_ALPHA = 0,
    ALPHA     = 1,
};

enum is_empty
{
    NOT_EMPTY    = 0,
    FIRST_EMPTY  = 1,
    SECOND_EMPTY = 2,
    BOTH_EMPTY   = 3,
};

is_empty IsEmpty         (char* str1, char* str2);

compare StrCmp           (char* str1, char* str2);
compare LinearComparator (char elem1, char elem2);

//comparators
int CmpLengthUP        (const void* str1, const void* str2);
int CmpLengthDown      (const void* str1, const void* str2);
int CmpAlphabet        (const void* str1, const void* str2);
int CmpAlphabetReverse (const void* str1, const void* str2);
//--------------------
int CheckFile       (FILE* file);
int IfSpace         (const char* string);

void CheckFclose     (FILE* file_ptr);
void StringSwap      (char** a, char** b);
void Dtor            (struct file_t* files);
void SortText        (struct file_t* files);
void PrintBuffer     (struct file_t* files);
void BubbleSort      (char** buffer, int len);
void CountLines      (struct file_t* files, size_t size);
void FillingAddr     (struct file_t* files, size_t size);
void FilesProcessing (struct file_t* files, size_t size);
void DefineComp      (struct file_t* files, const char* comparator);
void ReadArgs        (struct file_t* files, struct stat* unsort_inf, int argc, char* argv[]);

#endif
