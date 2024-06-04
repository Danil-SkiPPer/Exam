#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    char name[50];
}Data;

void inputArrayData(Data* dataArray, int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        printf("Enter name of struct [%d]:", i+1);
        scanf("%s", &dataArray[i].name);
        printf("Enter value of struct [%d]:", i+1);
        scanf("%d", &dataArray[i].value);
        printf("\n");
    }
}



void safeDataToFile (Data* dataArray, int size)
{
    FILE* taskFile = fopen("task.txt", "w");
    if(!taskFile){printf("ERROR FILE NOT FOUND"); exit(0);}
    for(int i = 0 ; i < size ; i++)
    {
        fprintf(taskFile, "Name of struct [%d]: %s  value of struct [%d]: %d\n", i+1, dataArray[i].name, i+1 , dataArray[i].value);
    }
}

int main()
{
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    Data* dataArray = (Data*)malloc(size* sizeof(Data));
    inputArrayData(dataArray, size);
    safeDataToFile(dataArray, size);
    return 0;
}
