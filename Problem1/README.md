# Problem 1

Korean: [http://euler.synap.co.kr/prob_detail.php?id=1](http://euler.synap.co.kr/prob_detail.php?id=1)

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

### 상식적인 수준에서 loop 1000번을 돌고 그 중에 3의 배수, 5의 배수가 걸러지는 if문의 수를 구한 뒤 sum 변수에 누적하여 합을 구한다