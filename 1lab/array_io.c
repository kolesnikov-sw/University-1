#include <stdio.h>
#include "array_io.h"

void inputArray(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void printArray(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}