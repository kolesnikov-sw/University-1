#include <stdio.h>

int main()
{
    int n;

    printf("Введите натуральное число: ");
    scanf("%d", &n);

    while (n >= 10)
        n /= 10;

    printf("Первая цифра: %d\n", n);

    return 0;
}