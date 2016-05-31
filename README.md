# experiment-gdb-debug-var<BR>
this is an experiment for combinience to use gdb debug for stdc.<BR>
<BR>
1. gcc compile time<BR>
   gcc -g d.c -o d.exec<BR>
   if you prefer, add -O0 <BR>
<BR>
2. invoke gdb<BR>
   gdb d.exec<BR>
<BR>
3. add break point<BR>
  break f<BR>
  run<BR>
<BR>
4. add watch variable<BR>
   watch x[8]<BR>
<BR>
5. go next line<BR>
   please type n or next<BR>
<BR>
6. gdb print out<BR>
   shown bellow.<BR>
<BR>
$ gdb d.exec<BR>
<pre>
GNU gdb (Ubuntu 7.7.1-0ubuntu5~14.04.2) 7.7.1
Copyright (C) 2014 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from d.exec...done.
(gdb) watch x[8]
No symbol "x" in current context.
(gdb) break f
Breakpoint 1 at 0x400535: file d.c, line 5.
(gdb) r
Starting program: /home/cobweb/d.exec 

Breakpoint 1, f () at d.c:5
5            int* x = malloc(10 * sizeof(int));
(gdb) watch x[8]
Hardware watchpoint 2: x[8]
(gdb) n
Hardware watchpoint 2: x[8]

Old value = 4195667
New value = 0
f () at d.c:6
6            x[8] = 0;        // problem 1: heap block overrun
(gdb) 
</pre>
<BR>
7. change and dump variables(this is danger)<BR>
if you type bellow, variable would change.<BR>
(gdb) p x[8] = 33<BR>
this would check with bellow.<BR>
(gdb)  x /32b 0x602030<BR>
0x602030:   0x21 0x00 0x00...<BR>
<BR>
8. Consideration<BR>
(1) you could use valgrind with perf record -e mem: if you get address of watch variable on gdb.<BR>
(2) if you print &x[8] you see specific address, but that is static or not ?<BR>
    i got 0x602030 in my env.<BR>
