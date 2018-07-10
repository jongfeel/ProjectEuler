# Problem 2

Korean: [http://euler.synap.co.kr/prob_detail.php?id=2](http://euler.synap.co.kr/prob_detail.php?id=2)

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

- 사실 python으로 피보나치 수열을 generator로 구하는 코드를 알고 있었음
- 피보나치 수열의 값이 4,000,000 이하일떄 까지 루프를 돌면서 2로 나눠서 나머지가 0인 값 => 즉 짝수 값만 체크해서 합을 구함