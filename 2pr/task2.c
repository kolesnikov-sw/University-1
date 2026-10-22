#include <stdio.h>

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

void filterWords(char str[])
{
    int i = 0;
    int j = 0;
    int k;
    int start;

    while (str[i] != '\0')
    {
        while (str[i] == ' ' || str[i] == '\t' ||
               str[i] == '\n' || str[i] == '\r')
            i++;

        start = i;

        while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' &&
               str[i] != '\n' && str[i] != '\r')
            i++;

        if (str[start] == 'A' || str[start] == 'D' ||
            str[start] == 'K' || str[start] == 'P')
        {
            if (j > 0)
                str[j++] = ' ';

            for (k = start; k < i; k++)
                str[j++] = str[k];
        }
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

    filterWords(str);

    printf("Результат:\n");
    printString(str);

    return 0;
}
