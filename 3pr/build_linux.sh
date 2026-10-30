#!/bin/sh
set -eu
cd "$(dirname "$0")"

gcc -std=c11 -Wall -Wextra -g -O0 -fPIC -c array.c -o array.o
gcc -shared array.o -Wl,-soname,libarray.so.1 -o libarray.so.1.0
ln -sfn libarray.so.1.0 libarray.so.1
ln -sfn libarray.so.1 libarray.so

gcc -std=c11 -Wall -Wextra -g -O0 -fPIC -c matrix.c -o matrix.o
gcc -shared matrix.o -Wl,-soname,libmatrix.so.1 -o libmatrix.so.1.0
ln -sfn libmatrix.so.1.0 libmatrix.so.1
ln -sfn libmatrix.so.1 libmatrix.so

gcc -std=c11 -Wall -Wextra -g -O0 main.c load.c -o app -ldl
printf '%s\n' 'Собраны app, libarray.so.1.0 и libmatrix.so.1.0'
