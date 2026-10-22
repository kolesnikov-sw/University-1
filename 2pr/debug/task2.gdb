set pagination off
set confirm off
set charset UTF-8
break inputString
break printString
run < examples/task2.txt
where
info args
finish
where
x/s str
continue
where
info args
finish
where
continue
quit
