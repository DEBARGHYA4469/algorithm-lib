### Debugging with GDB 


$ g++ -g file.cpp 
$ gdb ./a.out


#  run/ r -> run the code 


$ info breakpoint # get information of all breakpoints 
(gdb) info b
Num     Type           Disp Enb Address            What
2       breakpoint     keep y   0x00005555555567d5 in main() at fres.cpp:123
        breakpoint already hit 1 time

(gdb) delete 2
(gdb) info b
No breakpoints or watchpoints.


$ next / n # next stop 
Breakpoint 2, main () at fres.cpp:123
123         fun1(1);
(gdb) next
125         return 0;
(gdb) next
126     }


$ step / s # step into the next function without skip 
(gdb) step
fun1 (x=1) at fres.cpp:108
108         cout << x << endl;

$ continue / c # this is similar to follow through to the next breakpoints 
(gdb) continue
Continuing.
2
1
4
[Inferior 1 (process 203122) exited normally]

$ frame / f: print the current frame 
(gdb) frame
#0  fun2 (x=4) at fres.cpp:104
104         cout << x << endl;

(gdb) backtrace
#0  fun2 (x=4) at fres.cpp:104
#1  0x0000555555556778 in fun1 (x=1) at fres.cpp:109
#2  0x00005555555567df in main () at fres.cpp:123


Breakpoint 2, main () at fres.cpp:123
123         fun1(1);
(gdb) info local
a = 2


(gdb) up # To go from callee to caller 
#1  0x00005555555567df in main () at fres.cpp:123
123         fun1(1);

