# Problem 15

## Lattice Paths

> Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.\
![Alt text](https://projecteuler.net/project/images/p015.gif)\
How many such routes are there through a 20×20 grid?

Korean: [http://euler.synap.co.kr/prob_detail.php?id=15](http://euler.synap.co.kr/prob_detail.php?id=15)\
English: [https://projecteuler.net/problem=15](https://projecteuler.net/problem=15)

## System Requirement

- Tool: Visual Studio Code
- Language: C
- Compiler: gcc.exe (MinGW.org GCC-6.3.0-1) 6.3.0
- Use MinGW

## MinGW Download (only windows)

- [https://sourceforge.net/projects/mingw/files/](https://sourceforge.net/projects/mingw/files/)

## Test - bash

Change directory git root: /Problem15
and compile

```bash
gcc Problem15.c
```

with debugging: [https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html#Debugging-Options](https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html#Debugging-Options)

```bash
gcc -g Problem15.c
```

> Windows Environment Settings\
> System Variable > Path > Add "C:\MinGW\bin" (Installed path)

Run

```bash
a
```

## Test - Visaul Studio Code

- Open folder "Problem15" by Visual Studio Code
- Check out settings: launch.json and tasks.json
  - launch.json
    - "miDebuggerPath": "C:/mingw/bin/gdb.exe"
    - Use MinGW installed your path
  - tasks.json
    - Use gdb debug: args[0] = "-g"
- Press F5 to debug start

## Solve

- 문제의 그림만 보고 조합의 문제라는 걸 알아낼 수 있다.
- 문제에서 그림에 나오는 경우의 수 6가지를 잘 살펴보면
  - 가로로 가는 경우의 수가 두 가지: 한 칸 가는 경우, 두 칸 가는 경우
  - 세로로 가는 경우의 수가 두 가지: 역시 한 칸 가는 경우, 두 칸 가는 경우
- 이걸 right, down으로 나열해 보면 다음과 같다.
  - right-right-down-down
  - right-down-right-down
  - right-down-down-right
  - down-right-right-down
  - down-right-down-right
  - down-down-right-right
- 그러면 순서에 상관 없이 down과 right를 두 번씩 뽑는 4개의 순서의 조합을 만들어 내면 된다.
- 순서가 상관 없고 중복이 허용되므로 [Combination](https://en.wikipedia.org/wiki/Combination)으로 C(n, r)로 식은 n! / r!(n-r)! 이고 C(4, 2)로 대입해서 풀어보면 4 x 3 x 2 x 1 / 2 x 1 x 2 x 1 = 6이 나온다.
- 사실 공식은 인터넷 검색하면 나오는 거니 중요한건 아니고
- n개의 순서를 나열하기 위해 r의 가짓수를 가진다고 했을 때 경우의 수를 구해야 한다는 생각을 해내면 답을 찾을 수 있다.
- 그러면 문제에서 20x20 grid에서의 경우의 수이므로 가로 20번 세로 20번 해서 총 40번이 나열될 것이고 가짓수는 right, down을 20번씩 40개를 나열해서 뽑는 경우의 수이므로 C(40, 20)을 계산해 구하면 엄청나게 큰 숫자가 나오게 되어 있다.
- 이걸 사람이 계산하면 힘들고 짜증나므로 인터넷에 Combination calulator를 쳤을 때 나오는 사이트를 이용해서 계산해 본다.
- [https://www.calculatorsoup.com/calculators/discretemathematics/combinations.php](https://www.calculatorsoup.com/calculators/discretemathematics/combinations.php)
- 실제 계산 하면 답은 나오지만 이 문제를 푸는 이유 중 하나가 프로그래밍 해서 코드로 만들어야 한다는 걸 잊으면 안된다.
- 그런데 이 문제를 풀기 위해 선택한 C언어가 가지는 data type으로는 표현할 수 없는 크기의 수 이므로, 큰 숫자를 표현하는 다른 방법을 사용해야 한다.
- 무모하게 시도해 보려 했던 코드는 일단 짜 두고 github log에 남겨둔다.

## Solve - Programming

- 사실 실제 수학에서는 문제될 일이 없는 거지만 이걸 프로그래밍으로 풀어내려면 큰 숫자를 다룰 수 있는 뭔가를 만들어 내야 한다.