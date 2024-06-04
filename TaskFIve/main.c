#include <stdio.h>
#include <stdlib.h>
#include "tasklib.h"

#define SIZE 10


int main()
{
    srand(time(NULL));
    int* array[SIZE];
    generateRandArray(&array, SIZE);
    printArray(&array,SIZE);
    int summa = sumOfArray(&array, SIZE);
    printf("\nSumma of array: %d\n", summa);
    return 0;
    free(array);
}
