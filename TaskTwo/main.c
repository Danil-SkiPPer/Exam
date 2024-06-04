#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void generateRandArray (int* randArray, int size)
{
    for (int i = 0; i < size ; i++)
    {
        randArray[i] = (rand() % 101);
    }
}

void printArray (int* randArray, int size)
{
    printf("Rand array:\n");
    for(int i = 0 ; i < size ; i++)
    {
        printf("Array element [%d]: %d\n", i+1, randArray[i]);
    }
}

void arrayFileSafe(int* randArray, char* fileName , int size)
{
    FILE* taskFile = fopen(fileName, "w");
    if (!taskFile){printf("FILE NOT FOUND"); exit(0);}
    for(int i = 1 ; i <= size ; i += 2)
    {
        fprintf(taskFile, "Rand element of array [%d]: %d\n", i+1, randArray[i]);
    }
    fclose(taskFile);
}

int main()
{
    srand(time(NULL));
    int randArray[SIZE];
    generateRandArray(&randArray, SIZE);
    printArray(&randArray, SIZE);
    arrayFileSafe(&randArray, "task.txt", SIZE);
    return 0;
}
