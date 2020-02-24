# Problem 20

## Factorial digit sum

n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

Korean: [http://euler.synap.co.kr/prob_detail.php?id=20](http://euler.synap.co.kr/prob_detail.php?id=20)\
English: [https://projecteuler.net/problem=20](https://projecteuler.net/problem=20)

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

Change directory git root: /Problem20
and compile

```bash
gcc Problem20.c -lgmp
```

with debugging: [https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html#Debugging-Options](https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html#Debugging-Options)

```bash
gcc -g Problem20.c -lgmp
```

> Windows Environment Settings\
> System Variable > Path > Add "C:\MinGW\bin" (Installed path)

Run

```bash
a
```

## Test - Visaul Studio Code

- Open folder "Problem20" by Visual Studio Code
- Check out settings: launch.json and tasks.json
  - launch.json
    - "miDebuggerPath": "C:/mingw/bin/gdb.exe"
    - Use MinGW installed your path
  - tasks.json
    - Use gdb debug: args[0] = "-g"
    - Use gmplib: args[2] = "-lgmp"
- Press F5 to debug start

## Solve - GMP

- 마침 마지막으로 풀어야할 문제의 언어가 C 언어이고, 100!의 값은 C언어로 구하려면 15번 문제에서 풀었던 GMP를 사용하면 구할 수 있다는 걸 알게 된다.
- 게다가 15번 문제에는 Combination을 구하기 위해 코딩을 했지만 이미 Factorial 함수가 준비되어 있으므로 그대로 사용해서 100!에 해당하는 char* 값을 얻어온다.

https://github.com/jongfeel/ProjectEuler/blob/24fc5d6c6ee62c565a478a1e1215475ae6c4fe36/Problems/Problem15/Problem15.c#L5

- 그리고 char*의 길이를 구한 후에 for loop을 돌려 각 char[index] 값을 얻어 오면 이걸 char '0' 값에서 빼주면 int 값으로 변하게 된다.

``` C
char ch = '9';
int num = ch - '0'; // num is 9
```

- for loop 돌린 김에 각 int 값을 sum 해보면 원하는 값을 얻을 수 있다.
