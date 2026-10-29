#include <stdio.h>
#include <stdlib.h>
#include "work.h"

#define ROWS 4
#define COLS 11

static void fillMatrix(int s[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            s[i][j] = rand() % 101 - 50;
    }
}

static void printMatrix(int s[][COLS])
{
    printf("Матрица S (%dx%d):\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            printf("%4d", s[i][j]);
        printf("\n");
    }
}

static int sumMatrix(int s[][COLS], int x, int y)
{
    int sum = 0;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (s[i][j] >= x && s[i][j] <= y)
                sum += s[i][j];
        }
    }

    return sum;
}

EXPORT void run(int x, int y)
{
    int s[ROWS][COLS];

    fillMatrix(s);
    printMatrix(s);
    printf("Сумма элементов в [%d, %d]: %d\n", x, y, sumMatrix(s, x, y));
}
