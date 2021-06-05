# Problem 27

## Quadratic primes

Euler discovered the remarkable quadratic formula:

    pow(n, 2) + n + 41

It turns out that the formula will produce 40 primes for the consecutive integer values 0 <= n <= 39. However, when n = 40, pow(40, 2) + 40 + 41 == 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, pow(41, 2) + 41 + 41 is clearly divisible by 41.

The incredible formula pow(n, 2) - 79 * n + 1601 was discovered, which produces 80 primes for the consecutive values 0 <= n <= 79. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

    pow(n, 2) + a * n + b, where |a| < 1000 and |b| <= 1000

    where |n| is the modulus/absolute value of n
    e.g. |11| == 11 and |-4| == 4

Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n == 0.

Korean: [http://euler.synap.co.kr/prob_detail.php?id=27](http://euler.synap.co.kr/prob_detail.php?id=27)\
English: [https://projecteuler.net/problem=27](https://projecteuler.net/problem=27)

## Selected programming language

Javascript, 2020 Top languages over the years 1st.

## Analysis

우선 문제에 제시된 식대로 해서 n < 39 까지 돌려보면 아래와 같은 소수들이 나열된다.

41
43
47
53
61
71
83
97
113
131
151
173
197
223
251
281
313
347
383
421
461
503
547
593
641
691
743
797
853
911
971
1033
1097
1163
1231
1301
1373
1447
1523
1601

맨 마지막 값인 1601이 두번째 식의 계수에 해당하는게 힌트가 아닐까 하는 생각이 든다.

즉 pow(n, 2) - 79 * n + 1601 식에서 연속된 소수들을 찾아냈을 때 맨 마지막 소수가 세번째 식의 계수가 될 확률을 예측해 볼 수 있지 않을까 싶다.

어쨌든 a, b가 절대값 1000 내에서 움직여야 하므로 a의 범위는 2000개 b의 범위 역시 2000개 하면 총 4000000 loop 내에 n 만큼의 범위의 loop가 추가되면 답이 나올 것 같긴 하다. 흔한 brute force 방식이다.

### Optimization



## Design



## Ready to development environment

- [Visual Studio Code 1.56.2](https://code.visualstudio.com/)
- SDK: [Node 16.3.0](https://nodejs.org/en/)

## Build and run

Change directory from git root

``` bash
cd Problems/Problem27
```

and build and run

``` bash
node problem27.js
```