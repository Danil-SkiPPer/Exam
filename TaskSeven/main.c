#include <stdio.h>
#include <stdlib.h>



int maxArrayElem (int* array,int size)
{
    int max = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max) {max = array[i];}
    }
    return max;
}


int minArrayElem (int* array,int size)
{
    int min = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] < min) {min = array[i];}
    }
    return min;
}

int main()
{
    int size;
    printf("Enter the length of the array: ");
    scanf("%d", &size);
    int* dataArray = (int*)malloc(size*sizeof(int));
    if (dataArray == NULL){printf("ERROR"); exit(0);}
    for (int i = 0; i < size ; i++)
    {
        printf("Enter array element [%d]: ", i+1);
        scanf("%d", &dataArray[i]);
    }
    int maxValue = maxArrayElem(dataArray, size);
    int minValue = minArrayElem(dataArray, size);
    printf("\nMax value of array: %d\nMin value of array: %d\n", maxValue, minValue);
    return 0;
}
