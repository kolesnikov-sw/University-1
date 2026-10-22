#include <stdio.h>
#include <string.h>
#include "string_io.h"

#define SIZE 256

void removePairs(char str[])
{
    int i = 0;
    int j = 0;
    int length = strlen("ас");

    while (str[i] != '\0')
    {
        if (strncmp(str + i, "ас", length) == 0)
            i += length;
        else
            str[j++] = str[i++];
    }

    str[j] = '\0';
}

int main(void)
{
    char str[SIZE] = "";

    printf("Введите строку до точки:\n");
    if (!inputString(str, SIZE))
    {
        printf("Ошибка: нужна строка до точки длиной не более 255 байт.\n");
        return 1;
    }

    removePairs(str);

    printf("Результат:\n");
    printString(str);

    return 0;
}
