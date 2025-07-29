# ONEGIN
## About task

The project is named after Alexander Sergeevich Pushkin's novel in verse, "Eugene Onegin". The main purpose is to sort strings of roman "Eugene Onegin" in different ways. In alphabetical order, in length oder, reverse orders, etc. But original text does not change, sorted version of the roman is located in another file, so you can see both version of "Onegin" (sort.txt, unsort.txt). Of course "Eugene Onegin"
is just an example, the program can sort any text, that user wnats.

## How to use

To start the program you have to clone repository and compile all files.

```C
$ make
```

After building the program you should choose comparator. Comparator in common is a function that compares two elementary objects, in this project it's - strings. So you migth choose in which way original text will be sort. There is the table with all comparators:

| comparator | sorting |
|------------|---------|
| alphabet   | Strings will sort in alphabetical order from A to W, with out difference between registers, spaces in strings and any non-letter symbols |
| alphabet_reverse | Reverse alphabetical order, It works exactly the same way like comparator alphabet |
| length_up   | Strings will sort in ascending order of length from the smallest to the biggest length |
| length_down | Оn the contrary: from the biggest to the smallest |

To run the programm you have to write
name of comparator you need:

```C
$ make alphabet

or

$ make length_down
```
## Tools

### Self-made StrCmp(const char* str1, const char* str2)

```strcmp(const char* str1, const char* str2)``` - standart function that compares two strings.

```StrCmp(const char* str1, const char* str2)``` - my fynction that compares two strings by symbols, includes empty-string checker, letter checker, dynamic movement and comparison on strings, supports letter registers (ignore difference between 'A' and 'a').

### Modes of sorting

There are built-in bubble sort algorithm by function ```BubbleSort()``` and quick sort by standart function - ```qsort()```. To choose algorith of sort you have to change mode in the source code.

QSORT_MODE - mode for quick sort.

BUBBLE_MODE - mode for bubble sort.

Define needed mode and undef no-nedded.

```C
//modes:
#define QSORT_MODE
#define BUBBLE_MODE
```
Quick sort as an algorithm is quicker than bubble sort, so if you need to sort large file, you should use QSORT_MODE.

### Massive of addresses

To compare all strings I use massive of addresses of the begining of all strings, so the main text that I save in buffer is not change, only massive of addresses changes. It's very quickly!


