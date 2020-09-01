# Problem 23

## Non-abundant sums

A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number *n* is called deficient if the sum of its proper divisors is less than *n* and it is called abundant if this sum exceeds *n*.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

Korean: [http://euler.synap.co.kr/prob_detail.php?id=23](http://euler.synap.co.kr/prob_detail.php?id=23)\
English: [https://projecteuler.net/problem=23](https://projecteuler.net/problem=23)

## System Requirement

- Tool: Visual Studio Code 1.47.2
- Language: C++
- Compiler: g++.exe (MinGW.org GCC-6.3.0-1) 6.3.0
- Use MinGW

## MinGW Download (only windows)

- [https://sourceforge.net/projects/mingw/files/](https://sourceforge.net/projects/mingw/files/)
- Install packages
  - mingw32-base: Basic MinGW
  - mingw32-gcc-g++: The GNU C++ Compiler

## Test - bash

Change directory git root: /Problem18
and compile

```bash
g++ Problem23.cpp
```

[with debugging](https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html#Debugging-Options)

```bash
g++ -g Problem23.cpp
```

> Windows Environment Settings
> System Variable > Path > Add "C:\MinGW\bin" (Installed path)

Run

```bash
a
```

## Test - Visaul Studio Code

- Open folder "Problem23" by Visual Studio Code
- Check out settings: launch.json and tasks.json
  - launch.json
    - "miDebuggerPath": "C:/mingw/bin/gdb.exe"
    - Use MinGW installed your path
  - tasks.json
    - Use gdb debug: args[0] = "-g"
- Press Ctrl + Shift + B to Build
- Press F5 to debug start

## Abundant number

- 우선 abundant number가 무엇인지 부터 알고 시작해야 한다.
- 초과수, 과잉수라는 뜻이 있는 abundant number는 문제에 설명에도 있듯이 proper divisor[dɪˈvaɪzə(r)]의 합보다 큰 수를 의미한다.
- Proper divisor는 진약수의 뜻으로 자기 자신을 제외한 약수이다.

## Reuse and apply function

- [21번 문제](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem21)에서 이미 proper divisor의 합을 구하는 함수를 만든 적이 있으므로 이 함수를 응용해서 abundant 함수를 구한다.

https://github.com/jongfeel/ProjectEuler/blob/0d84e0fed82ed8845b86edf7921b6043f049fe09/Problems/Problem21/Program.cs#L8

## Limit

- 가장 작은 abundant수는 12이고 그 두수의 합은 24라고 문제에 주어졌으니, abundant를 구하기 위한 최소 시작 값은 12임을 알 수 있다.
- 또 28123을 넘어가는 수는 두 abundant number로 보여진다고 했으니, abundant를 구하기 위한 최대 loop는 28123임을 알 수 있다.
- 그럼 아래와 같이 for문을 작성할 수 있다.

``` cpp
for (int i = 12; i <= 28123; i++)
{
  // ...
}
```

- 나중에 최적화 하면서 for문을 바꿨는데 마지막 단락의 optimized를 확인한다.
- 이렇게 reverse for loop을 만들면 Abundant가 아닌 수의 합을 위해 초기화를 진행하고 동시에 abundant 수를 구하면서 체크해 나갈 수 있다.

``` cpp
for (int i = 28123; i > 0; i--)
{
  // ...
}
```

## IsAbundant function

- 약수를 구하고 합을 구하기 전까지는 abundant한지 알 수 없으므로 아래와 같이 함수를 정의한다.

``` cpp
bool IsAbundant(int number);
```

- 어떤 수를 IsAbundant 함수의 파라미터로 넣으면 그 수가 abundant인지를 판단하는 함수이다.
- 내부 구현은 파라미터로 받은 수의 proper divisor의 합을 구하고 파라미터의 수 보다 큰지 비교를 해서 결과를 리턴한다.

## Sum of two abundant

- 반드시 두 abundant의 합을 구해야 하므로 nC2의 조합 (Combination)을 구하고 그 수의 합을 구하는게 맞다.
- 그런데 12부터 28123까지의 for loop 안에서 n개 까지의 abundant number를 구해 나갈 것이므로 3개 이상 부터는 n-1까지 loop을 돌면서 마지막 n을 차례대로 합한 수를 구하고 마지막으로 n + n 까지를 구하면 계속해서 모든 abundant 수가 n까지 있을 때 두 abundant의 합을 (누적해서) 구할 수 있다.
  - 예)
  - 12가 하나 있을 때는 12+12 밖에 안되므로 24는 시작부터 제외 시킬 수 있으며
  - 12 다음 abundant number는 18인데 12+18, 18+18의 두 조합을 생각해 볼 수 있으며
  - 그 다음 abundant number인 20이 나온다면, 12+20, 18+20, 20+20 이런식으로 구해 나갈 수 있게 된다.
  - 또 그 다음 abundant number인 24가 나오면, 12+24, 18+24, 20+24, 24+24를 구해 나가면
  - 결국 n까지의 누적된 두 abundant number의 합을 구할 수 있다.

## Check sum of two abundant

- 두 Abundant수의 합이 아닌 걸 찾아내야 하고 12 부터 28123까지를 계속 체크해야 하므로 [10번 문제](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem10)에서 썼던 에라토스테네스의 체 아이디어를 응용한다.
- 두 수의 합에 해당하는 숫자가 나오면 그 숫자에 해당하는 index의 value를 0으로 바꿔준다.
- 가장 마지막에 list의 sum을 구하면 두 abundant 수의 합이 아닌 모든 양의 정수의 합을 구할 수 있다.
- C++로 구현해야 하므로 이 list는 vector< int > 변수로 아래와 같이 정의할 수 있다.
- 여기까지 읽고도 이해가 안될 수 있으므로 [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)를 참고한다.

``` cpp
vector<int> NotSumOfTwoAbundantNumbers;
```

## Solve

- 위의 개념을 모두 조합해서 문제를 푼다.
- 28123부터 1까지 for loop을 거꾸로 돈다.
- NotSumOfTwoAbundantNumbers에 index에 해당하는 값을 index 값으로 assign 한다.
- IsAbundant로 abundant 수인지 확인한 후 AbundantNumbers에 추가한다.
- abundant number인지를 체크하기 위해 여태까지 구한 abundant number들의 for loop을 돌면서 두 abundant number의 합을 구해 나간다.
- 그 수에 해당하는 NotSumOfTwoAbundantNumbers의 index 값을 0으로 세팅해서 지워 나간다.
  - 단 index 28123이 넘지 않는 선에서 0으로 세팅한다. (prevent OutOfRangeException)
- 최종적으로 NotSumOfTwoAbundantNumbers의 sum을 구하면 답을 얻을 수 있다.

## Maintanence

### Optimized

- Vector < int > NotSumOfTwoAbundantNumbers의 경우 index에 해당하는 값 역시 index여야 하므로 초기화가 필요하긴 하다.
- 그래서 최초에 초기화 시켜주는 for loop을 만들었다. 아래 commit diff 참고
- [11530405](https://github.com/jongfeel/ProjectEuler/commit/11530405ce3f98343fa926e1a904861a0a355e8e#diff-a3787ca0674b0d81c6bfed1dc2e2aa6d)
- 그런데 다시 보니 또 12 부터 28123 까지 loop을 돌아야 하는데 이걸 한번에 돌릴 수 없을까를 고민하다가 reverse for loop으로 바꿨다.
- 힌트는 Sum of two abundant를 구하면 반드시 현재 index에 해당하는 수는 IsAbundant로 체크가 되고 abundant가 맞을 때 그 수 보다는 큰 숫자들이 index가 될 수 밖에 없으므로 reverse for loop을 돌리되 Sum of two abundant의 index가 28123이 넘지 않도록 체크만 해주면??
- Vector < int > NotSumOfTwoAbundantNumbers에 index에 해당하는 index 값을 넣어줌과 동시에 이미 reverse for loop에서 지나간 index에 해당하는 Sum of two abundant의 index를 0으로 만들 수 있기에 바꿨다.
- 이건 자랑할만함!