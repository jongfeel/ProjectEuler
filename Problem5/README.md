# Problem 5

## Smallest multiple
> 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.\
What is the smallest positive number that is *evenly divisible* (divisible with no remainder) by all of the numbers from 1 to 20?

Korean: [http://euler.synap.co.kr/prob_detail.php?id=5](http://euler.synap.co.kr/prob_detail.php?id=5)\
English: [https://projecteuler.net/problem=5](https://projecteuler.net/problem=5)

## System Requirement

- Tool: Visual Studio Code
- Language: C++
- Compiler: g++.exe (MinGW.org GCC-6.3.0-1) 6.3.0
- Use MinGW

## MinGW Download (only windows)

- [https://sourceforge.net/projects/mingw/files/](https://sourceforge.net/projects/mingw/files/)

## Test - bash

Change directory git root: /Problem5
and compile

```bash
g++ Problem5.cpp
```

[with debugging](https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html#Debugging-Options)

```bash
g++ -g Problem5.cpp
```

> Windows Environment Settings
> System Variable > Path > Add "C:\MinGW\bin" (Installed path)

Run

```bash
a
```

## Test - Visaul Studio Code

- Open folder "Problem5" by Visual Studio Code
- Check out settings: launch.json and tasks.json
  - launch.json
    - "miDebuggerPath": "C:/mingw/bin/gdb.exe"
    - Use MinGW installed your path
  - tasks.json
    - Use gdb debug: args[0] = "-g"
- Press F5 to debug start

## Solve

- 문제에 답이 있다. 1 ~ 10 의 숫자로 나누기가 되는 수를 구하는 건 소인수 분해를 하는 것과 같다. 즉 prime factor의 수들만으로 나누기를 해도 구할 수 있다는 생각을 할 수 있다는 뜻이다. 2, 3, 5, 7의 숫자가 소인수 분해가 가능한 prime factor이며 이 숫자들로 나누기를 하면 된다. 단, 2x2, 2x2x2, 3x3, 3x3x3, 4x4...  등등 제곱수도 고려해야 한다.
- 예) 24의 경우 소인수분해: 2x2x2x3이 되는데 이는 2^3x3으로 표현한다.
- 따라서 1 ~ 10의 숫자로 나누기가 되는 수를 다시 나열해 보면 2, 3, 4(2^2), 5, 7, 8(2^3), 9(3^2)가 되는 걸 알수 있고 이 factor로 나누어 떨어지는 수를 찾아 보면 2520이 나오는 걸 알 수 있다.
- 1 ~ 20의 숫자로 나누어 떨어지는 수는 다시 말하면 2520의 배수만큼의 숫자 중에서 11 ~ 20의 숫자로 나누어 떨어지는 수를 찾는 것과 같음을 알 수 있다. 굳이 1 ~ 10 사이로 떨어지는 숫자를 구할 필요가 없는 것이고 2520의 배수만큼의 숫자는 항상 1 ~ 10 사이의 숫자로 나누어 떨어지는 수라는 걸 보장해 준다.
- 그러면 11 ~ 20 사이의 숫자 중에 소수와 제곱수를 나열해 보면 11, 13, 16(2^4), 17, 19의 수들이며 2520의 배수의 수들 중에 이 수들로 나누어 떨어지는 작은 수를 구해보면 된다.