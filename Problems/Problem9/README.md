# Problem 9

## Special Pythagorean triplet

> A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,\
a^2 + b^2 = c^2\
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.\
There exists exactly one Pythagorean triplet for which a + b + c = 1000.\
Find the product abc.

Korean: [http://euler.synap.co.kr/prob_detail.php?id=9](http://euler.synap.co.kr/prob_detail.php?id=9)\
English: [https://projecteuler.net/problem=9](https://projecteuler.net/problem=9)

## System Requirement

- Tool: Visual Studio Code
- Language: C
- Compiler: gcc.exe (MinGW.org GCC-6.3.0-1) 6.3.0
- Use MinGW

## MinGW Download (only windows)

- [https://sourceforge.net/projects/mingw/files/](https://sourceforge.net/projects/mingw/files/)

## Test - bash

Change directory git root: /Problem9
and compile

```bash
gcc Problem9.c
```

with debugging
https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html#Debugging-Options

```bash
gcc -g Problem9.c
```

> Windows Environment Settings\
> System Variable > Path > Add "C:\MinGW\bin" (Installed path)

Run

```bash
a
```

## Test - Visaul Studio Code

- Open folder "Problem9" by Visual Studio Code
- Check out settings: launch.json and tasks.json
  - launch.json
    - "miDebuggerPath": "C:/mingw/bin/gdb.exe"
    - Use MinGW installed your path
  - tasks.json
    - Use gdb debug: args[0] = "-g"
- Press F5 to debug start

## Solve

- 주어진 조건에 만족하면서 a, b, c를 무식하게 구해보려 하면 단순히 a < 1000, b < 1000, c < 1000에 해당하는 triple for loop을 돌려보면 된다고 생각할 수 있지만 이건 10억번의 for문을 돌아야 하므로 주어진 문제의 조건에 맞도록 잘 계산해 봐야 한다.
- 우선 첫번째 for문 해석
  - a=1부터 시작: 길이가 0인 도형은 없으므로 1부터 시작한다.
  - 332 의미: a + b + c = 1000 이고 a < b < c 라는 조건을 만족하는 a의 최대값은 332이다. b, c는 적어도 a 보다는 커야 하므로 332 < 333 < 334 <= 1000의 조건을 만족하는 a의 최대값은 332이다.
- 두번째 for문 해석
  - b는 적어도 a보다 커야 하므로 초기값은 a+1 부터 시작한다.
  - b의 경우는 a가 최대 332 까지 돈다고 가정했을 때 b 역시 최대한 도는 수를 고려해 본다면 c는 최소한 b 보다는 커야 하므로 c의 최대값 334를 계산해서 1000 - 334 - a의 값으로 계산해 볼 수 있다.
  - a는 1 ~ 332 까지이므로 b는 자연스럽게 a+1 부터 해서 334 ~ 665 사이의 수로 최대값 범위가 좁혀지게 된다.
- c값 해석
  - c의 경우는 a + b + c = 1000의 공식에서 유도 가능하다. 따라서 c = 1000 - a - b로 계산해서 334 ~ 997 사이의 수로 가늠해 볼 수 있다.
- nested for loop에서 이미 a < b가 되게 초기값을 넣어 줬으므로 b < c의 조건이 만족하는 수만 계산해 본다. if (b >= c)의 조건 부터는 계산할 필요가 없으므로 break로 빠져나온다.
- 문제에서 a^2 + b^2 = c^2은 단 하나만 있다고 했으므로 if 문에 걸리면 nested for loop을 빠져나오기 위해 결과를 출력한 후 goto 문으로 빠져 나온다.

## Solve2

- 주어진 조건 a + b + c = 1000,  a < b < c 를 다시 잘 생각해 보니 b의 loop문 조건과, b >= c의 조건도 생략 가능하다.
- 두번째 for문 재해석
  - b의 경우는 a가 최대 332 까지 돈다고 했을 때를 생각해 봤으므로, b는 333 까지 인건 맞다. 그런데 a=1일 때 한번 더 체크해 보면 b는 499 이상 돌 수 없다. 왜냐하면 a + b + c = 1000 과 a < b < c 조건을 만족하려면 a=1, b=499, c=500 까지 할 수 있으므로 b=499가 최대값이다.
- nested for loop에서 이미 a < b가 되게 초기값을 넣어 줬고, b 역시 c보다 클 수 없는 499의 값까지 loop문을 돌게 되어 있다. 그러므로 if문 조건 삭제가 가능하다.
- 기존 코드와 비교: [c08f5c](https://github.com/jongfeel/ProjectEuler/commit/c08f5cc113cf4beb16298f1a3753bca4ab2ca531)

## Review

- nested for loop를 빠져나오는데 goto문에 맛들리고 있다. 너무 편한 듯.