# Problem 6

## Sum square difference

> The sum of the squares of the first ten natural numbers is,\
1^2 + 2^2 + ... + 10^2 = 385\
The square of the sum of the first ten natural numbers is,\
(1 + 2 + ... + 10)^2 = 552 = 3025\
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.\
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

Korean: [http://euler.synap.co.kr/prob_detail.php?id=6](http://euler.synap.co.kr/prob_detail.php?id=6)\
English: [https://projecteuler.net/problem=6](https://projecteuler.net/problem=6)

## System Requirement

- Tool: Visual Studio Code
- Language: C++
- Compiler: g++.exe (MinGW.org GCC-6.3.0-1) 6.3.0
- Use MinGW

## MinGW Download (only windows)

- [https://sourceforge.net/projects/mingw/files/](https://sourceforge.net/projects/mingw/files/)

## Test - bash

Change directory git root: /Problem6
and compile

```bash
g++ Problem6.cpp
```

[with debugging](https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html#Debugging-Options)

```bash
g++ -g Problem6.cpp
```

> Windows Environment Settings
> System Variable > Path > Add "C:\MinGW\bin" (Installed path)

Run

```bash
a
```

## Test - Visaul Studio Code

- Open folder "Problem6" by Visual Studio Code
- Check out settings: launch.json and tasks.json
  - launch.json
    - "miDebuggerPath": "C:/mingw/bin/gdb.exe"
    - Use MinGW installed your path
  - tasks.json
    - Use gdb debug: args[0] = "-g"
- Press F5 to debug start

## Solve

- 역시 문제에 답이 있다.
- 언뜻 보면 쉬운 문제여서 그냥 for 문 돌려서 계산하면 답이 나오기 때문에 그렇게 답을 구하면 재미가 없다. 사실 이 계산은 컴퓨터한테 시키는게 아니라 사람이 만든 공식이 있으며 이 공식에 맞게 컴퓨터한테 계산 시키는게 더 빠르다.
- 저 덧셈의 규칙을 보면 위대한 수학자 가우스가 어린 시절 수업시간에 1 ~ 100 까지의 숫자를 더하는 문제를 가지고 덧셈의 법칙을 발견하고 빠르게 계산했다는 일화가 떠오르게 되어 있다.
- [https://ko.wikipedia.org/wiki/%EC%B9%B4%EB%A5%BC_%ED%94%84%EB%A6%AC%EB%93%9C%EB%A6%AC%ED%9E%88_%EA%B0%80%EC%9A%B0%EC%8A%A4](https://ko.wikipedia.org/wiki/%EC%B9%B4%EB%A5%BC_%ED%94%84%EB%A6%AC%EB%93%9C%EB%A6%AC%ED%9E%88_%EA%B0%80%EC%9A%B0%EC%8A%A4)
- 그러므로 우리는 위대한 수학자 가우스의 생각을 잘 읽을 수 있다면, 주어진 문제에 공식이 있을 것이라는 걸 눈치챌 수 있다.
- 즉, 예전부터 있었지만 우리는 여태까지 잘 몰랐던 자연의 법칙=수학의 원리를 찾아 계산하면 쉽게 풀리게 된다.
- 매우 유명한 수학 온라인 사이트인 brilliant.org에서 자연의 법칙 및 참된 수학의 진리를 확인해 보자
- [https://brilliant.org/wiki/sum-of-n-n2-or-n3/](https://brilliant.org/wiki/sum-of-n-n2-or-n3/)
- 위 공식에 따라 The square of the sum 의 공식은 n(n+1)/2 이며 여기에 제곱을 하게 되면 (n(n+1)/2)^2인 것을 알 수 있으며 n = 100일 때의 값을 구하면 된다.
- 또, The sum of the squares의 공식은 n(n+1)(2n+1)/6 이며 n = 100일 때의 값을 구하면 된다.
- 두 값을 구한 뒤에 차를 구하는 계산은 사람이 하면 귀찮으니 이 시점에 컴퓨터를 시켜서 답을 구해본다.

## Review

- 제곱수를 구하기 위해 pow 함수를 사용하는데, 문제는 int 값으로 떨어지지 않는다는 것이다.
- pow 함수에서 double형으로 계산되는 값을 round down하기 위해 floor 함수를 사용한다.
- 왠지 C, C++로 코딩하지 않았으면 floor 쓸 일이 없었을 것 같다. 좀 귀찮다.