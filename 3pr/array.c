#include <stdio.h>
#include <stdlib.h>
#include "work.h"

#define SIZE 11

static void fillArray(int m[])
{
    for (int i = 0; i < SIZE; i++)
        m[i] = rand() % 101 - 50;
}

static void printArray(const int m[])
{
    printf("Массив M (%d элементов):\n", SIZE);
    for (int i = 0; i < SIZE; i++)
        printf("%4d", m[i]);
    printf("\n");
}

static int sumArray(const int m[], int x, int y)
{
    int sum = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (m[i] >= x && m[i] <= y)
            sum += m[i];
    }

    return sum;
}

EXPORT void run(int x, int y)
{
    int m[SIZE];

    fillArray(m);
    printArray(m);
    printf("Сумма элементов в [%d, %d]: %d\n", x, y, sumArray(m, x, y));
}
