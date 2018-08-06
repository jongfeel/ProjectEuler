# Problem 1

## Multiples 3 and 5

> If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.\
Find the sum of all the multiples of 3 or 5 below 1000.

Korean: [http://euler.synap.co.kr/prob_detail.php?id=1](http://euler.synap.co.kr/prob_detail.php?id=1)]\
English: [https://projecteuler.net/problem=1](https://projecteuler.net/problem=1)

## System Requirement

- Tool: Visual Studio Code
- SDK: Java SDK 1.8.0_161-b12
- Language: Java

## Test - bash

```bash
javac Problem1.java
```

```bash
java Problem1
```

## Test - Visaul Studio Code

- Open folder "Problem1" by Visual Studio Code
- Check out settings - launch.json
- Press F5 to debug start

## Solve

- 상식적인 수준에서 loop 1000번을 돌고 그 중에 3의 배수, 5의 배수가 걸러지는 if문의 수를 구한 뒤 sum 변수에 누적하여 합을 구한다

## Solve2 - Advanced Java8

- Java8의 IntStream을 사용해서 filter, sum을 차례로 호출해 한 줄로 결과를 내도록 변경해 봄
- 기존 코드와 비교 [16a217](https://github.com/jongfeel/ProjectEuler/commit/16a21719810ad9acfeb6d8f3bcfab112b1c56652)

## Review

- Java가 현대적인 언어로 변신하기 위해 많이 바뀌고 있다는 걸 다시 한번 느낌
- filter, sum 이런 stream method의 경우는 다른 언어에서는 이미 오래전 부터 지원해 왔던 부분이라 사실 Java만 했던 사람이 아니라면 큰 감흥은 없을 것이라 본다
- 문법은 @functional interface라는 annotation 까지 붙여 가며 그럴싸하게 함수형으로 포장했지만 이게 아직도 Interface라는게 한계점 인 듯