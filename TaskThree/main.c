#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void inputDataArray (int* dataArray, int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        printf("Print element of array [%d of %d]: ", i+1, size);
        scanf("%d", &dataArray[i]);
    }
}

void printArray (int* dataArray, int size)
{
    printf("\nYour array:\n");
    for(int i = 0 ; i < size ; i++)
    {
        printf("Array element [%d]: %d\n", i+1, dataArray[i]);
    }
}

void arrayFileSafe(int* randArray, char* fileName , int size)
{
    FILE* taskFile = fopen(fileName, "w");
    if (!taskFile){printf("FILE NOT FOUND"); exit(0);}
    for(int i = 0 ; i < size ; i++)
    {
        fprintf(taskFile, "Element of array [%d]: %d\n", i+1, randArray[i]);
    }
    fclose(taskFile);
}


int main()
{
    int dataArray[SIZE];
    inputDataArray(&dataArray, SIZE);
    printArray(&dataArray, SIZE);
    arrayFileSafe(&dataArray, "task.txt" , SIZE);
    return 0;
}
