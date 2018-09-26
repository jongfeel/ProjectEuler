# Problem 15

## Lattice Paths

> Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.\
![Grid path](https://projecteuler.net/project/images/p015.gif)\
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

## MinGW library install gmplib

- Open MinGW installation manager
- All Packages > MinGW > MinGW Libraries > MinGW Standard Libraries
- Check mingw32-gmp, mingw32-libgmp, mingw32-libgmpxx
- ![MinGW Install Manager](https://github.com/jongfeel/ProjectEuler/blob/master/Problems/Problem15/MinGW%20installation%20manager%2C%20mingw32-gmp.png)

## Test - bash

Change directory git root: /Problem15
and compile

```bash
gcc Problem15.c -lgmp
```

with debugging: [https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html#Debugging-Options](https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html#Debugging-Options)

```bash
gcc -g Problem15.c -lgmp
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
    - Use gmplib: args[2] = "-lgmp"
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

## Solve - GMP

- 사실 실제 수학에서는 문제될 일이 없는 거지만 이걸 프로그래밍으로 풀어내려면 큰 숫자를 다룰 수 있는 뭔가를 만들어 내야 한다.
- 학부 시절에 연습용 과제로 아주 큰 수를 char[]로 해서 계산기를 만들었던 기억이 있다면 그렇게 만들어도 된다.
- 그런데 이 문제의 의도가 큰 수를 다루는 프로그래밍이 목적이 아니라는 것을 기억해야 하며
- 큰 수를 다루는 프로그래밍의 요구는 수십년 전 부터 있어왔을 것이므로 검색해 보면
- 우리는 훌륭한 선배님들이 만들어 놓은 아름다운 라이브러리를 만나게 된다.
- [GNU Multiple Precision Arithmetic Library (GMP)](https://en.wikipedia.org/wiki/GNU_Multiple_Precision_Arithmetic_Library)
- 이걸 사용해서 문제를 해결하면 된다.

## Solve - Programming

- 큰 수를 다루는 struct를 사용하고 그 struct를 연산해 주는 함수를 적절히 사용하면 큰 수의 계산이 가능해진다.
- 매뉴얼을 참고해서 설치방법 부터 해서 기본 적인 함수들에 대해 찾아보면 어렵지 않게 구현이 가능하다.
- [https://gmplib.org/manual/index.html#Top](https://gmplib.org/manual/index.html#Top)
- mpz_t는 포인터를 가지는 구조체이므로 선언한 후에 초기화/해제 함수를 만드시 사용해야 한다.
  - mpz_init_set_ui는 초기화 하면서 unsigned long int 값으로 초기값을 넣어준다.
  - mpz_clear는 해당 구조체의 메모리를 해제한다.
- mpz_mul_ui는 누산기 함수로 두번째 파라미터의 값에 세번째 파라미터인 unsigned long int 값을 곱해 첫번째 파라미터로 값을 세팅한다.
  - 이 함수를 n번 호출하면 자연스럽게 n factorial의 값을 구할 수 있게 된다.
- mpz_mul, mpz_divexact 함수는 곱셉과 나눗셈 함수로 mpz_t 구조체 자체를 연산할 수 없기 때문에 함수의 도움을 받아 연산을 한다.
- 나머지 주석 부분은 출력값 확인을 위한 것인데 mpz_get_str로 char*를 구할 수 있다. 두번째 파라미터인 base의 값은 말 그대로 base이며 진수 값을 넣으면 된다.
- 사실 설명을 하긴 했지만 매뉴얼 보고 하면 금방 할 수 있다.