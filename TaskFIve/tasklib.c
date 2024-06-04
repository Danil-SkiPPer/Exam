#include <stdio.h>
#include <stdlib.h>
#include "tasklib.h"

void generateRandArray (int* array, int size)
{
    for (int i = 0; i < size ; i++)
    {
        array[i] = (rand() % 101);
    }
}

int sumOfArray (int* array, int size)
{
    int summa = 0;
    for (int i = 0; i < size ; i++)
    {
        summa += array[i];
    }
    return summa;
}


void printArray (int* array, int size)
{
    printf("Array:\n");
    for(int i = 0 ; i < size ; i++)
    {
        printf("Array element [%d]: %d\n", i+1, array[i]);
    }
}
