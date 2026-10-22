#include <stdio.h>
#include "string_io.h"

int inputString(char str[], int size)
{
    int c;
    int i = 0;
    int overflow = 0;

    while ((c = getchar()) != EOF && c != '.')
    {
        if (i < size - 1)
            str[i++] = (char)c;
        else
            overflow = 1;
    }

    str[i] = '\0';
    return c == '.' && !overflow;
}

void printString(const char str[])
{
    puts(str);
}
