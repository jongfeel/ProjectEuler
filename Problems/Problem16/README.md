# Problem 16

## Power digit sum

> 2<sup>15</sup> = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.\
What is the sum of the digits of the number 2<sup>1000</sup>?

Korean: [http://euler.synap.co.kr/prob_detail.php?id=16](http://euler.synap.co.kr/prob_detail.php?id=16)\
English: [https://projecteuler.net/problem=16](https://projecteuler.net/problem=16)

## System Requirement

- Tool: Visual Studio Code
- Extension: Python extension for Visual Studio Code, Python 3.7.0
- Language: Python

## Test - bash

```bash
python Problem16.py
```

## Test - Visaul Studio Code

- Open folder "Problem16" by Visual Studio Code
- Check out settings - launch.json
- Check out python intalled path - settings.json
- Press F5 to debug start

## Solve

- [Problem2](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem2)에서 썼던 python의 enumerate + sum 의 조합을 이용해 본다.
- Python의 장점은 동적 언어이므로 Java나 .NET에서 큰 수를 다루기 위한 BigInteger type을 따로 사용하거나 [Problem15](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem15)을 풀 때 처럼 C, C++의 GMP를 쓰지 않아도 된다는 점이다.
- pow(2, 1000)을 구하면 지수 표기법이 아니라 10진수 그대로 출력되며 이걸 str로 변환하여 enumerate 시키면 str의 한 자리씩 for문을 돌리는게 가능하다.
- enumerate한 값은 tuple 형태인데 알다시피 index=0는 index, index=1은 value 이다.
- 그래서 val[1]을 가져오고 이걸 다시 int로 캐스팅 한 후 sum 함수를 호출해 각 자리수의 합을 구할 수 있다.

## Language review

- Python은 아름다운 언어인 것 같다. 모든 것이 함축적이고 명시적이다.
- The Zen of Python의 첫 문장이 이 문제의 코드를 말해주는 듯 하다.
- Beautiful is better than ugly.

```python
>>> import this
```