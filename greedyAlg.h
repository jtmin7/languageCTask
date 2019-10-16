#pragma
#include <stdio.h>
#include <stdbool.h>
#define ARRAY_SIZE 20

void copyArray(int* array1, int* array2, int arraySize);
void initArray(int* array, int initNum, int arraySize);
void initArray2(int* array1, int* array2, int initNum, int arraySize);
int getChangeNum(int* stdNumNumber, int* stdNum, int stdNumSize, int *startIndex, int inputNum, int limitValue);
void showChangNumArray(int* array, int stdNumSize, int* stdNum, int leastChangeNum);
int getLeastChangeNum(int inputNum, int* stdNum, int stdNumSize, bool showArray);