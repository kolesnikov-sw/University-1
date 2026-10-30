#include <stdio.h>
#include <dlfcn.h>
#include "load.h"

int loadRun(const char *name, int x, int y)
{
    void *lib;
    void (*fun)(int, int);
    const char *error;

    lib = dlopen(name, RTLD_LAZY);
    if (lib == NULL)
    {
        fprintf(stderr, "Не удалось загрузить %s: %s\n", name, dlerror());
        return 1;
    }

    /* Сбрасываем прошлую ошибку перед поиском функции. */
    dlerror();
    fun = (void (*)(int, int))dlsym(lib, "run");
    error = dlerror();
    if (error != NULL)
    {
        fprintf(stderr, "Не найдена функция run: %s\n", error);
        dlclose(lib);
        return 1;
    }

    printf("Загружена библиотека: %s\n", name);
    fun(x, y);

    if (dlclose(lib) != 0)
    {
        fprintf(stderr, "Ошибка выгрузки: %s\n", dlerror());
        return 1;
    }
    printf("Библиотека выгружена.\n");

    return 0;
}
