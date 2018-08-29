# Problem 11

## Largest product in a grid

> In the 20×20 grid below, four numbers along a diagonal line have been marked in red.\
08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08\
49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00\
81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65\
52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91\
22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80\
24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50\
32 98 81 28 64 23 67 10 **26** 38 40 67 59 54 70 66 18 38 64 70\
67 26 20 68 02 62 12 20 95 **63** 94 39 63 08 40 91 66 49 94 21\
24 55 58 05 66 73 99 26 97 17 **78** 78 96 83 14 88 34 89 63 72\
21 36 23 09 75 00 76 44 20 45 35 **14** 00 61 33 97 34 31 33 95\
78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92\
16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57\
86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58\
19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40\
04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66\
88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69\
04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36\
20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16\
20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54\
01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48\
The product of these numbers is 26 × 63 × 78 × 14 = 1788696.\
What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?

Korean: [http://euler.synap.co.kr/prob_detail.php?id=11](http://euler.synap.co.kr/prob_detail.php?id=11)\
English: [https://projecteuler.net/problem=11](https://projecteuler.net/problem=11)

## System Requirement

- Tool: Visual Studio Code
- Language: C++
- Compiler: g++.exe (MinGW.org GCC-6.3.0-1) 6.3.0
- Use MinGW

## MinGW Download (only windows)

- [https://sourceforge.net/projects/mingw/files/](https://sourceforge.net/projects/mingw/files/)

## Test - bash

Change directory git root: /Problem11
and compile

```bash
g++ Problem11.cpp
```

[with debugging](https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html#Debugging-Options)

```bash
g++ -g Problem11.cpp
```

> Windows Environment Settings
> System Variable > Path > Add "C:\MinGW\bin" (Installed path)

Run

```bash
a
```

## Test - Visaul Studio Code

- Open folder "Problem11" by Visual Studio Code
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

- 어떤 한 숫자로 부터 각 방향으로 숫자 네 개를 구해야 하는데
- 사실 방향은 나중에 구한다고 하더라도 for문의 구성은 바로 구현이 가능하다.
- 20x20 matrix 이므로 row에 해당하는 for문을 돌고, col에 해당하는 for문을 돈 후에 네 개의 숫자를 가지는 for문을 돌아 총 3개의 for문이 돌게 되면 각 자리마다 어떻게든 숫자 네 개씩은 구할 수가 있다. (index가 벗어나는 부분은 일단 논외)

### 방향에 대한 분석

- Matrix의 row, col을 모두 순회한다고 했을 때, 어느 한 숫자를 기준으로 여덟 방향의 네 개의 수를 구하는게 맞다고 생각할 수 있다.
- 그런데 for문은 순회는 어차피 left to right 순서대로 진행되며 index 0 부터 해서 진행 되므로 right to left의 숫자 네 개의 곱은 구할 필요가 없게 된다.
- 즉, 예제에 보이는 [6,8]의 26의 숫자는 이미 [6,5]에서 left to right 방향으로 숫자 네 개의 곱인 23x67x10x26을 구할 떄 곱해지는 수에 포함되어 있다.
- 따라서 [6,8]의 위치에서 right to left인 26x10x67x23의 곱은 구할 필요가 없어진다. 곱셈의 [교환 법칙(commulative law)](https://en.wikipedia.org/wiki/Commutative_property)이 성립한다는 걸 안다면 [0,0] 부터 [19,19] 까지 순회 할 떄 구할 필요가 없어지는 방향은 여덟 방향에서 반으로 줄어든다.
- 그런 의미에서 총 여덟 방향 중 교환법칙에 의해 구할 필요가 없는 네 방향은 제외하고 right, up-right, down-right, down 이 네 방향을 처음부터 끝까지 구하면 될 것이다.

### 방향별 네 개의 숫자 구하기

- for문의 성질을 잘 이용하면 방향을 구하는 건 어렵지 않다.
- 가장 안쪽의 k에 해당하는 for문이 20x20 matrix에 한 위치에서 어느 방향이든지 네 개의 숫자를 구하는 for문이다.
- 여기서 index를 벗어나는 예외 처리를 해 줘야 하는데 실제로 left to right 방향의 네 숫자의 곱을 구하는 건 index 17 부터 4자리 이상 구해지지 않기 때문에 자동으로 index 17은 세 개, index 18 은 두 개, index 19 는 한 개의 숫자가 구해지도록 for문을 만든다.
- 나머지 방향도 0보다 크게 그리고 20보다 작게 index를 구성하고 if문으로 걸러 주면 방향별 네 개라고 하더라도 index를 벗어나지 않게 알아서 세 개, 두 개, 한 개로 곱셈을 진행한다.
- 각 방향별로 네 개의 수를 구하고 곱셈을 한 값을 나중에 모두 max 함수를 통해 [i, j]의 위치에서 방향별 네 개의 숫자를 곱한 값 중 가장 큰 값을 구한다.
- matrix의 한 자리에서 max 값을 구한 후, 다음 max값을 구하기 위해 곱셈의 항등원인 1로 세팅해서 matrix의 모든 자리에서 방향 별 숫자 네 개의 곱이 가장 큰 수를 구해 나간다.