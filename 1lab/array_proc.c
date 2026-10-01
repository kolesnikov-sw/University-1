#include "array_proc.h"

int deleteFirstPositive(int a[], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            for (j = i; j < n - 1; j++)
                a[j] = a[j + 1];

            return n - 1;
        }
    }

    return n;
}

void changeArray(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
            a[i] = a[i] * a[i];
        else
            a[i] = a[i] * 2;
    }
}