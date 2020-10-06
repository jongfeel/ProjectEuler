# Problem 25

## 1000-digit Fibonacci number

The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.

Hence the first 12 terms will be:

F1 = 1\
F2 = 1\
F3 = 2\
F4 = 3\
F5 = 5\
F6 = 8\
F7 = 13\
F8 = 21\
F9 = 34\
F10 = 55\
F11 = 89\
F12 = 144

The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

Korean: [http://euler.synap.co.kr/prob_detail.php?id=25](http://euler.synap.co.kr/prob_detail.php?id=25)\
English: [https://projecteuler.net/problem=25](https://projecteuler.net/problem=25)

## System Requirement

- Tool: Visual Studio Code
- Language: C
- Compiler: gcc.exe (MinGW.org GCC-6.3.0-1) 6.3.0
- Use MinGW

## MinGW Download (only windows)

- [https://sourceforge.net/projects/mingw/files/](https://sourceforge.net/projects/mingw/files/)

## MinGW library install gmplib

- Open MinGW installation manager
- All Packages > MinGW > MinGW Libraries > MinGW Standard Libraries
- Check mingw32-gmp, mingw32-libgmp, mingw32-libgmpxx
- ![MinGW Install Manager](https://github.com/jongfeel/ProjectEuler/blob/master/Problems/Problem15/MinGW%20installation%20manager%2C%20mingw32-gmp.png)

## Test - bash

Change directory git root: /Problem25
and compile

```bash
gcc Problem25.c -lgmp
```

with debugging: [https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html#Debugging-Options](https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html#Debugging-Options)

```bash
gcc -g Problem25.c -lgmp
```

> Windows Environment Settings\
> System Variable > Path > Add "C:\MinGW\bin" (Installed path)

Run

```bash
a
```

## Test - Visaul Studio Code

- Open folder "Problem25" by Visual Studio Code
- Check out settings: launch.json and tasks.json
  - launch.json
    - "miDebuggerPath": "C:/mingw/bin/gdb.exe"
    - Use MinGW installed your path
  - tasks.json
    - Use gdb debug: args[0] = "-g"
    - Use gmplib: args[2] = "-lgmp"
- Press F5 to debug start
