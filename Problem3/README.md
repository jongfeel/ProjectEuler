# Problem 3

Korean: [http://euler.synap.co.kr/prob_detail.php?id=3](http://euler.synap.co.kr/prob_detail.php?id=3)

English: [https://projecteuler.net/problem=3](https://projecteuler.net/problem=3)

## System Requirement

- Tool: Visual Studio Community 2017
- Language: Visual Basic .NET
- Framework: .NET Core 2.0
- Visual Studio Project: .NET Core Console App

## Test - bash

```bash
vbc Problem3.vb
```

## Test - Visaul Studio Community 2017

- Open folder "Problem3" by Visual Studio Community 2017
- Check out install packages - .NET Core 2.0
- Press F5 to debug start

## Solve

- Prime number 구하는 알고리즘은 흔하다.
- 하지만 주어진 문제의 수가 아주 크므로 2부터 시작해서 소수를 구하는 건 바보같은 짓이므로
- 역으로 주어진 문제의 수 보다 작은 숫자의 소수를 구해서 prime factor를 구한다
- prime factor의 특성상 첫 factor가 구해지면 그 수와 같거나 작은 factor의 값이 구해지지 큰 factor의 값을 구할 필요가 없어진다.
- O(n)의 시간 복잡도 만큼의 소수 구하는 알고리즘을 구하고 그 와중에 주어진 숫자의 prime factor를 차례대로 구하면 답을 찾는 것이 가능하다.
- 예제로 나온 factor의 수를 살펴봐도 5, 7, 13, 29이므로 13195 부터 작은 숫자의 prime number를 구하면서 factor를 구하면 된다.