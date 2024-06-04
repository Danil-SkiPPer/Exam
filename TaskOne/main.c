#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchDublicate (char* buffer, char** dataArray, int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        if (strcmp(buffer, dataArray[i]) == 0) {return 1;}
    }
    return 0;
}

int scanFileInfo (char* fileName, char*** dataArray)
{
    FILE* taskFile = fopen(fileName, "r+");
    if (!taskFile){printf("NAME FILE NOT FOUND"); exit(0);}
    int count = 0; char buffer[50];
    *dataArray = (char**)malloc(sizeof(char*));
    while(fgets(buffer, sizeof(buffer), taskFile))
    {
        *dataArray = (char**)realloc(*dataArray, (count+1)*sizeof(char*));
        buffer[strcspn(buffer, "\n")] = '\0';
        if (searchDublicate(buffer, *dataArray, count)== 0)
        {
            (*dataArray)[count] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
            strcpy((*dataArray)[count], buffer);
            count++;
        }
    }
    fclose(taskFile);
    return count;
}

void printArray (char** dataArray, int size)
{
    for(int i =0 ; i < size ; i++)
    {
        printf("String [%d] : %s\n", i + 1, dataArray[i]);
    }
}

int main()
{
    char** dataArray;
    int size = scanFileInfo("text.txt", &dataArray);
    printArray(dataArray, size);
    for(int i = 0 ; i < size ; i++) {free(dataArray[i]);}
    free(dataArray);
    return 0;
}
