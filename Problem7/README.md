# Problem 7

## 10001st prime

> By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.\
What is the 10001st prime number?

Korean: [http://euler.synap.co.kr/prob_detail.php?id=7](http://euler.synap.co.kr/prob_detail.php?id=7)\
English: [https://projecteuler.net/problem=7](https://projecteuler.net/problem=7)

## System Requirement

- Tool: Visual Studio Code
- Extension: Python extension for Visual Studio Code, Python 3.7.0
- Language: Python

## Test - bash

```bash
python Problem7.py
```

## Test - Visaul Studio Code

- Open folder "Problem7" by Visual Studio Code
- Check out settings - launch.json
- Check out python intalled path - settings.json
- Press F5 to debug start

## Solve

- 소수 판별하는 문제를 2번에서 풀었기 때문에 IsPrime 함수를 이용해서 풀어본다.
- 주어진 순번 만큼 while 문을 돌리고 3부터 차례대로 2씩 증가시킨다.
  - 3부터 하는 이유: 어차피 2는 소수이므로 2의 count를 계산해서 count = 1 부터 시작한다.
  - index = 1 부터 해서 2씩 증가하는 이유: index가 2의 배수, 즉 짝수인 수는 판별 해보나마나 소수가 아니다. 이렇게 하면 10001번째 까지 구하는데 10001번이 아닌 5001번의 loop문으로 구하는게 가능해진다.
  - IsPrime으로 판별하는 시간 마저 아깝다면 에라토스테네스의 체 아이디어를 이용해서 처음부터 index의 값 중에 2, 3, 5, 7의 modular 값이 0인 숫자는 continue를 해주는 방법도 있다. 이렇게 하면 범위가 매우 좁혀진다. (이렇게 까지 하지 않아도 충분히 빠른 시간에 답은 구해잔다.)
- 그런데 10001번째의 소수가 얼마나 큰지 알수 없으므로 단순하게 for문을 돌리다 보면 값이 늦게 출력된다.
- 문제 2번에서 구했던 힌트를 통해 소수의 sqrt 즉 제곱근 까지만 구하면 소수인지 아닌지 판별할 수 있도록 math.sqrt를 이용한다.
- Python에서 range 함수는 float 형을 지원하지 않으므로 math.floor을 사용해서 소수점을 버리고 + 1을 더해준다.
  - +1을 해주는 이유: Python에서 range(1, 10)이라고 하면 1 ~ 9 까지 범위이다.
  - 정수 값 만큼의 range를 판별해야 하기 때문에 .00001 ~ .9999의 소수점 값이 버려진다 하더라도 +1 만큼의 수만큼 더 돌려준다.