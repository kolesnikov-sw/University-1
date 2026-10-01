#include <stdio.h>
#include "array_io.h"
#include "array_proc.h"

#define N 20

int main()
{
    int a[N];

    printf("Введите 20 элементов массива:\n");
    inputArray(a, N);

    changeArray(a, N);

    printf("Полученный массив:\n");
    printArray(a, N);

    return 0;
}