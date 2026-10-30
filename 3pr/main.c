#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "load.h"

#ifdef _WIN32
#include <windows.h>
#define ARRAY_LIB "./array.dll"
#define MATRIX_LIB "./matrix.dll"
#else
#define ARRAY_LIB "./libarray.so"
#define MATRIX_LIB "./libmatrix.so"
#endif

int main(void)
{
    int choice;
    int x, y;

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    srand((unsigned int)time(NULL));

    while (1)
    {
        printf("\n1 - массив M (11)\n2 - матрица S (4x11)\n0 - выход\n");
        printf("Ваш выбор: ");
        if (scanf("%d", &choice) != 1)
        {
            fprintf(stderr, "Ошибка: введите целое число.\n");
            return 1;
        }

        if (choice == 0)
            break;
        if (choice != 1 && choice != 2)
        {
            printf("Выберите 1, 2 или 0.\n");
            continue;
        }

        printf("Введите X и Y (X <= Y): ");
        if (scanf("%d%d", &x, &y) != 2)
        {
            fprintf(stderr, "Ошибка: нужны два целых числа.\n");
            return 1;
        }
        if (x > y)
        {
            printf("Ошибка: X должен быть не больше Y.\n");
            continue;
        }

        if (choice == 1)
            loadRun(ARRAY_LIB, x, y);
        else
            loadRun(MATRIX_LIB, x, y);
    }

    return 0;
}
