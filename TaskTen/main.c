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
        printf("Element of struct [%d]: Value 1: %d, Value 2: %d\n", i+1, arrayData[i].dataOne, arrayData[i].dataTwo);
    }
}

int maxValue (Data* dataArray, int size)
{
    int max = dataArray[0].dataOne;
    for (int i = 0 ; i < size ; i++)
    {
        if (dataArray[i].dataOne > max){max = dataArray[i].dataOne;}
    }
    for (int i = 0 ; i < size ; i++)
    {
        if (dataArray[i].dataTwo > max){max = dataArray[i].dataTwo;}
    }
    return max;
}

int minValue (Data* dataArray, int size)
{
    int min = dataArray[0].dataOne;
    for (int i = 0 ; i < size ; i++)
    {
        if (dataArray[i].dataOne < min){min = dataArray[i].dataOne;}
    }
    for (int i = 0 ; i < size ; i++)
    {
        if (dataArray[i].dataTwo < min){min = dataArray[i].dataTwo;}
    }
    return min;
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
    int min = minValue(arrayData, sizeDataOne);
    int max = maxValue(arrayData,  sizeDataOne);
    printf("\nMax value: %d \nMin value: %d\n", max, min);
    return 0;
}
