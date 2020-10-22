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

## Analysis

### Fibonacci number

[Problem2](../Problem2/)가 피보나치 문제였으므로 이 피보나치 함수를 응용해서 피보나치 수를 구한다.
단, 파라미터로 digits 값을 주면 피보나치 value의 index를 주는 형태로 바꿔본다.

### 1000 digits

보통 프로그래밍 언어에서 변수의 type이 지원하는 숫자의 범위가 정해져 있다.
그래도 1000자리까지 지원하는 type은 없으므로 [Problem15](../Problem15/)에서 사용했던 [GMP](https://en.wikipedia.org/wiki/GNU_Multiple_Precision_Arithmetic_Library)를 사용한다.

## Design

### Fibonacci 함수 구현

Problem2와 다른 방식으로 함수를 구현해야 한다.
Problem2는 python으로 작성했고 특정 숫자를 파라미터로 전달하면 그 숫자에 도달할 때 까지의 피보나치 수를 계속해서 리턴하는 generator 함수를 작성했었다.

``` python
def Fibonacci(untilNumber):
```

C 언어로 짤 때는 파라미터로 digits 값을 준다 그러면 그 digits에 해당하는 피보나치 수 index를 리턴하는 함수를 구현한다. index는 항상 1보다 크므로 리턴값은 unsigned int로 받는다.

``` c
unsigned int Fibonacci(int digits)
```

[mpz_add](https://gmplib.org/manual/Integer-Arithmetic#Integer-Arithmetic)로 덧셈 연산을 진행하고
[mpz_get_str](https://gmplib.org/manual/Converting-Integers#Converting-Integers)로 결과값의 char*를 구한 후 이걸 strlen 함수를 호출해 길이를 구한다. 길이가 파라미터 값인 digits가 되는 시점에 Fibonacci 값에 해당하는 index를 return해 준다.
