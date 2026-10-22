#include <stdio.h>
#include <string.h>

#define SIZE 256

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
