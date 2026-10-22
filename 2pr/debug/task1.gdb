set pagination off
set confirm off
set charset UTF-8
break task1.c:29
commands
printf "n = %d, last = %d\n", n, last
continue
end
run < examples/task1.txt
quit
