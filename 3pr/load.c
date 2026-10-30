#include <stdio.h>
#include "load.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

int loadRun(const char *name, int x, int y)
{
    void (*fun)(int, int);

#ifdef _WIN32
    HMODULE lib = LoadLibraryA(name);
    if (lib == NULL)
    {
        fprintf(stderr, "Не удалось загрузить %s. Код ошибки: %lu\n",
                name, (unsigned long)GetLastError());
        return 1;
    }

    fun = (void (*)(int, int))GetProcAddress(lib, "run");
    if (fun == NULL)
    {
        fprintf(stderr, "Не найдена функция run. Код ошибки: %lu\n",
                (unsigned long)GetLastError());
        FreeLibrary(lib);
        return 1;
    }
#else
    void *lib;
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
#endif

    printf("Загружена библиотека: %s\n", name);
    fun(x, y);

#ifdef _WIN32
    if (!FreeLibrary(lib))
    {
        fprintf(stderr, "Ошибка выгрузки. Код ошибки: %lu\n",
                (unsigned long)GetLastError());
        return 1;
    }
#else
    if (dlclose(lib) != 0)
    {
        fprintf(stderr, "Ошибка выгрузки: %s\n", dlerror());
        return 1;
    }
#endif
    printf("Библиотека выгружена.\n");

    return 0;
}
