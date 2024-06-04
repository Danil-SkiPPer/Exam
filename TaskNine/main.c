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
        printf("Enter name of struct [%d of %d]:", i+1,size);
        scanf("%s", &dataArray[i].name);
        printf("Enter value of struct [%d of %d]:", i+1, size);
        scanf("%d", &dataArray[i].value);
        printf("\n");
    }
}



void safeDataToFile (Data* dataArray, int size)
{
    FILE* nameFile = fopen("names.txt", "w");
    if(!nameFile){printf("ERROR FILE NOT FOUND"); exit(0);}
    FILE* valueFile = fopen("values.txt", "w");
    if(!valueFile){printf("ERROR FILE NOT FOUND"); exit(0);}
    for(int i = 0 ; i < size ; i++)
    {
        fprintf(nameFile, "Name of struct [%d]: %s  \n", i+1, dataArray[i].name);
        fprintf(valueFile, "Value of struct [%d]: %d\n", i+1 , dataArray[i].value);
    }
}

int main()
{
    int size = 5;
    Data* dataArray = (Data*)malloc(size* sizeof(Data));
    inputArrayData(dataArray, size);
    safeDataToFile(dataArray, size);
    return 0;
}
