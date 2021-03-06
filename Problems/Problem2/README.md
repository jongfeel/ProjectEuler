# Problem 2

## Even Fibonacci numbers

> Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:\
1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...\
By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

Korean: [http://euler.synap.co.kr/prob_detail.php?id=2](http://euler.synap.co.kr/prob_detail.php?id=2)\
English: [https://projecteuler.net/problem=2](https://projecteuler.net/problem=2)

## System Requirement

- Tool: Visual Studio Code
- Extension: Python extension for Visual Studio Code, Python 3.6.5
- Language: Python

## Test - bash

```bash
python Problem2.py
```

## Test - Visaul Studio Code

- Open folder "Problem2" by Visual Studio Code
- Check out settings - launch.json
- Press F5 to debug start

## Solve

- 사실 python으로 피보나치 수열을 generator로 구하는 코드를 알고 있었기 떄문에 참고해서 구현했다.
- 이미 알고 있는 피보나치 수열 구하는 방법을 다른 언어의 recursive function기법으로 구현하면 시간 복잡도가 증가하는 방식이므로 처음부터 O(n)의 복잡도를 가지도록 python의 generator 문법으로 구현하는게 필연적이다.
- 피보나치 수열의 값이 4,000,000 이하일떄 까지 루프를 돌면서 2로 나눠서 나머지가 0인 값 => 즉 짝수 값만 체크해서 합을 구함

## Solve - use sum function

- python의 for in 문 뒤에 if문을 연결해서 짝수를 구하고 바로 sum function을 사용해서 합을 구해서 한줄로 구현
- 기존 코드와 비교 [07660b](https://github.com/jongfeel/ProjectEuler/commit/07660b352f0a14248d82e14cd9b73bc6e69b5b99)

## Review

- {} 중괄호가 없는 Python을 하다 보면 처음엔 힘들지만, 옛날에 나온 언어 치고는 코드를 상당히 깔끔하게 짤 수 있다는게 장점인 것 같다.