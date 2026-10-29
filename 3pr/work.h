#ifndef WORK_H
#define WORK_H

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

/* У обеих библиотек одна сигнатура точки входа. */
EXPORT void run(int x, int y);

#endif
