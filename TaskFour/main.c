#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dataOne;
    int dataTwo;
}Data;

int readArrayFromFile (char* filename , int** dataArray)
{
    int size = 0 ;
    FILE* taskFile = fopen(filename, "r+");
    if (!taskFile){printf("FILE %s NOT FOUND", filename); exit(0);}
    *dataArray = (int*)malloc(sizeof(int));
    while(fscanf(taskFile, "%d", &(*dataArray)[size]) != EOF)
    {
        size++;
        *dataArray = (int*)realloc(*dataArray, (size+1)*sizeof(int));
    }
    fclose (taskFile);
    return size;
}

void  printArrayData (Data* arrayData , int size, char* text)
{
    printf("\n%s\n", text);
    for (int i = 0 ; i < size ; i++)
    {
        printf(" Value 1: %d , Value 2: %d\n",arrayData[i].dataOne, arrayData[i].dataTwo);
    }
}

Data*  dataToArray(int* dataArrayOne, int* dataArrayTwo, int size , Data* arrayData)
{
    arrayData = (Data*)malloc(size * sizeof(Data));
    for(int i = 0 ; i < size ; i++)
    {
        arrayData[i].dataOne = dataArrayOne[i];
        arrayData[i].dataTwo =dataArrayTwo[i];
    }
    free(dataArrayOne);
    free(dataArrayTwo);
    return arrayData;
}

void arrayFileSafe(Data* arrayData, char* fileName , int size)
{
    FILE* taskFile = fopen(fileName, "w");
    if (!taskFile){printf("FILE NOT FOUND"); exit(0);}
    for(int i = 0 ; i < size ; i++)
    {
        fprintf(taskFile, "Element of struct [%d]: Value 1: %d, Value 2: %d\n", i+1, arrayData[i].dataOne, arrayData[i].dataTwo);
    }
    fclose(taskFile);
}


int main()
{
    Data* arrayData;
    int* dataArrayOne;
    int* dataArrayTwo;
    int sizeDataOne = readArrayFromFile("valueOne.txt", &dataArrayOne);
    int sizeDataTwo = readArrayFromFile("valueTwo.txt", &dataArrayTwo);
    if (sizeDataOne != sizeDataTwo){printf("ERROR OF DATA"); exit(0);}
    arrayData = dataToArray(dataArrayOne,dataArrayTwo, sizeDataOne, arrayData);
    printArrayData(arrayData, sizeDataOne, "Your array");
    arrayFileSafe(arrayData, "task.txt", sizeDataOne);
    return 0;
}
