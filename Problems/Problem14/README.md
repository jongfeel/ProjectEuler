# Problem 14

## Longest Collatz sequence

The following iterative sequence is defined for the set of positive integers:

*n* → *n*/2 (*n* is even)\
*n* → 3*n*+ 1 (*n* is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

**NOTE:** Once the chain starts the terms are allowed to go above one million.

Korean: [http://euler.synap.co.kr/prob_detail.php?id=14](http://euler.synap.co.kr/prob_detail.php?id=14)\
English: [https://projecteuler.net/problem=14](https://projecteuler.net/problem=14)

## System Requirement

- Tool: Visual Studio Code
- Language: C++
- Compiler: g++.exe (MinGW.org GCC-6.3.0-1) 6.3.0
- Use MinGW

## MinGW Download (only windows)

- [https://sourceforge.net/projects/mingw/files/](https://sourceforge.net/projects/mingw/files/)
- Install packages
  - mingw32-base: Basic MinGW
  - mingw32-gcc-g++: The GNU C++ Compiler

## Test - bash

Change directory git root: /Problem14
and compile

```bash
g++ Problem14.cpp
```

[with debugging](https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html#Debugging-Options)

```bash
g++ -g Problem14.cpp
```

> Windows Environment Settings
> System Variable > Path > Add "C:\MinGW\bin" (Installed path)

Run

```bash
a
```

## Test - Visaul Studio Code

- Open folder "Problem14" by Visual Studio Code
- Check out settings: launch.json and tasks.json
  - launch.json
    - "miDebuggerPath": "C:/mingw/bin/gdb.exe"
    - Use MinGW installed your path
  - tasks.json
    - Use gdb debug: args[0] = "-g"
- Press Ctrl + Shift + B to Build
- Press F5 to debug start

## Solve

### 문제 분석

- 100만 까지 for loop을 돌면서 홀수/짝수 구분한 다음에 수식 계산해서 계산한 count를 세고 그 중에 가장 큰 숫자를 구하면 되는 거라 생각함
- 그런데 이미 100만의 숫자 중에서라는 단서가 붙었으므로 보나마나 코드 짜면 오래 걸려서 안될 거라는 걸 직감적으로 알 수 있음
- 느낌이, dynamic programming을 해야 할 듯

### 아니 그런데!

- 그냥 돌려보면 0.5ms 내에 답이 나오네???
- 왜 그런건지 생각해 봤는데 C++ 이어서 속도가 빠른 것일 수도 있는 데다가 컴퓨터 성능이 좋아서일 수도 있을 듯 하다.

### 진짜 힌트

- 문제에 힌트가 있는데 1000000이나 되는 큰 숫자를 계산하다 보면 int type의 범위를 벗어나는 큰 숫자가 등장하는데 그것만 조심하면 될 듯 하다. unsigned long long type인 size_t를 쓰면 엄청나게 큰 숫자도 감당할 수 있다.
