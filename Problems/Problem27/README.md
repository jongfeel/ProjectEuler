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

a와 b에 대한 모든 정수를 탐색할 게 아니라 소수가 나오는 범위를 정해 놓는다면 4000000 loop를 안돌려도 될 수 있다.

우선 n = 1일 때 a와 b의 상태를 체크해 본다.

> 1 + a + b

이 식이 소수가 되어야 하는데 모든 소수는 홀수 이므로 결국 a + b는 짝수여야 한다는 결론이 나온다.

- 짝수 + 짝수 = 짝수
- 짝수 + 홀수 = 홀수
- 홀수 + 짝수 = 홀수
- 홀수 + 홀수 = 짝수

짝수가 나오는 경우의 수는 a와 b 모두 짝수이거나 모두 홀수이면 된다. 논리 게이트로 얘기하면 a [xnor](https://en.wikipedia.org/wiki/XNOR_gate) b의 결과를 얻으면 되므로 홀수가 나오는 경우는 loop 문에서 제외 (continue) 시킨다.

이렇게 하면 총 탐색해야 하는 범위가 무려 50%가 줄어들어 2000000의 loop 안에서 탐색하면 되므로 최적화가 가능해진다.

## Design

원래 brute force 방식의 for loop는 아래와 같다.

- |a| < 1000 for loop
- |b| < 1000 for loop
- continuous isPrime count while loop

``` javascript
for (let a = -999; a < 1000; a++) {
    for (let b = -999; b < 1000; b++) {
        let n = 0;
        while (isPrime(n ** 2 + a * n + b)) {
            n++;
        }
        // get result of a multiply b when maximum n
    }
}
```

그리고 javascript로 짠 isPrime 함수는 아래와 같다.

Problem 3에서 작성한 IsPrime 함수에서 number < 2 조건을 추가하고 javascript 버전으로 바꿔봤다.

https://github.com/jongfeel/ProjectEuler/blob/df20739bb43fdf731027ba833943aee5e6ca9850/Problems/Problem3/Problem3/Program.vb#L28-L35

``` javascript
const isPrime = number => {
    if (number < 2) {
        return false;
    }

    const sqrt = Math.sqrt(number);
    for (let i = 2; i <= sqrt; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
};
```

### Optimization

그런데 n = 1 일때 1 + a + b 이 소수(홀수)여야 하고 그러면 a + b가 짝수여야 하므로 짝수 + 짝수, 홀수 + 홀수만 짝수가 될 수 있으므로 이 조건이 아닌 a와 b에 대해서는 소수 판단 함수를 태우지 않는 쪽으로 한다.

그래서 간단히 짝수를 판별하는 함수인 isEven 을 추가하고 if문을 추가해서 설계한다.

``` javascript
const isEven = number => number % 2 == 0;

for (let a = -999; a < 1000; a++) {
    for (let b = -999; b < 1000; b++) {
        if ( (isEven(a) && !isEven(b)) || (!isEven(a) && isEven(b)) ) {
            continue;
        }
        let n = 0;
        while (isPrime(n ** 2 + a * n + b)) {
            n++;
        }
        // get result of a multiply b when maximum n
    }
}
```

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