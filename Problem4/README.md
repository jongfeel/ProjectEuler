# Problem 4

Korean: [http://euler.synap.co.kr/prob_detail.php?id=4](http://euler.synap.co.kr/prob_detail.php?id=4)

English: [https://projecteuler.net/problem=4](https://projecteuler.net/problem=4)

## System Requirement

- Tool: Visual Studio Code
- Language: C
- Compiler: gcc.exe (MinGW.org GCC-6.3.0-1) 6.3.0
- Use MinGW

## MinGW Download (only windows)

- [https://sourceforge.net/projects/mingw/files/](https://sourceforge.net/projects/mingw/files/)

## Test - bash

Change directory git root: /Problem4
and compile

```bash
gcc Problem4.c
```

> Windows Environment Settings

> System Variable > Path > Add "C:\MinGW\bin" (Installed path)

Run

```bash
a
```

## Test - Visaul Studio Code

- Open folder "Problem4" by Visual Studio Code
- Check out settings: launch.json and tasks.json
    - launch.json
        - "miDebuggerPath": "C:/mingw/bin/gdb.exe"
        - Use MinGW installed your path
    - tasks.json
        - Use gdb debug: args[0] = "-g"
- Press F5 to debug start

## Solve

