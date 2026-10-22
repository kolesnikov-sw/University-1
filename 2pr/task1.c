#include <stdio.h>

int main(void)
{
    int n;
    int last;
    int found = 0;

    printf("Введите натуральные числа. Для завершения введите 0:\n");

    while (1)
    {
        if (scanf("%d", &n) != 1)
        {
            printf("Ошибка: нужно ввести целое число.\n");
            return 1;
        }

        if (n == 0)
            break;

        if (n < 0)
        {
            printf("Ошибка: число должно быть натуральным.\n");
            return 1;
        }

        last = n % 10;
        if (last == 7)
        {
            printf("%d\n", n);
            found = 1;
        }
    }

    if (!found)
        printf("Подходящих чисел нет.\n");

    return 0;
}
