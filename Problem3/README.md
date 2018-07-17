# Problem 3

Korean: [http://euler.synap.co.kr/prob_detail.php?id=3](http://euler.synap.co.kr/prob_detail.php?id=3)

English: [https://projecteuler.net/problem=3](https://projecteuler.net/problem=3)

## System Requirement

- Tool: Visual Studio Community 2017
- Language: Visual Basic .NET
- Framework: .NET Core 2.0
- Visual Studio Project: .NET Core Console App

## Test - bash

Change directory git root: /Problem3
and compile

```bash
dotnet build
```

Run

```bash
dotnet run
```

## Test - Visaul Studio Community 2017

- Open visual studio solution file "Problem3.sln" by Visual Studio Community 2017
- Check out install packages - .NET Core 2.0 and Visual Basic Environment
- Press F5 to debug start

## Solve

- Prime number 구하는 알고리즘은 흔하다.
- 잘 생각해 보면 실제로 prime factor를 구해서 나눠 가면서 구하는게 답인 것 같다.
- 이 전에 쓴 글에서는 주어진 숫자보다 작은 prime number를 구하는 거였는데, 그렇게 가면 생각보다 훨씬 많은 prime number를 구하면서 factor를 찾아야 하므로
- 정공법으로 구해본다.
- 생각을 바꾼 이유는 factor로 나눗셈을 하는 과정에서 끝까지 구해야 하는 prime number와 factor의 범위는 n/factor로 더욱 작아지므로 결국 뒤에서 찾는 것 보다 더 빨리 찾을 수 있다.
- 시간 복잡도 역시 O(n)으로 결정될 수 있다. n보다 작은 factor를 찾아낸다면 n은 급격히 줄어들지만 최악의 경우의 factor는 자기 자신인 n일 수 있으므로 결국 factor를 찾아내는 과정은 최대 n이다.