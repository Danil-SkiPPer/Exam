#include <stdio.h>
#include <stdlib.h>
#include "main.h"



int main()
{
    int value1; printf("Imput 1st value: "); scanf("%d", &value1);
    int value2; printf("Imput 2nd value: "); scanf("%d", &value2);
    int summa = sumValue(value1,value2);
    int maximum = maxValue(value1,value2);
    printf("Summa of %d and %d is %d\nMaximum value: %d",value1, value2, summa, maximum);
    return 0;
}
