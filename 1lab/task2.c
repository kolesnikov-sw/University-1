#include <stdio.h>
#include "array_io.h"
#include "array_proc.h"

#define N 26

int main()
{
    int a[N];
    int n = N;

    printf("Введите 26 элементов массива:\n");
    inputArray(a, n);

    n = deleteFirstPositive(a, n);

    printf("Полученный массив:\n");
    printArray(a, n);

    return 0;
}