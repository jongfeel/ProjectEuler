# Problem 3

## Largest prime factor

> The prime factors of 13195 are 5, 7, 13 and 29.\
What is the largest prime factor of the number 600851475143 ?

Korean: [http://euler.synap.co.kr/prob_detail.php?id=3](http://euler.synap.co.kr/prob_detail.php?id=3)\
English: [https://projecteuler.net/problem=3](https://projecteuler.net/problem=3)

## System Requirement

- Tool: Visual Studio Community 2017
- Language: Visual Basic .NET
- Framework: .NET Core 2.0
- Visual Studio Project: .NET Core Console App

## .NET Core 2.1 SDK Downloads (If you do not want Visual Studio Community 2017)

- [https://www.microsoft.com/net/download](https://www.microsoft.com/net/download)

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
- 처음에는 주어진 숫자보다 작은 prime number를 차례로 구하면 될거라 생각했는데, 그렇게 하면 생각보다 훨씬 많은 prime number를 구하면서 factor를 찾아야 한다.
- 그래서 다시 정공법으로 구해보는 걸로 바꿨는데 그 이유는 factor로 나눗셈을 하는 과정에서 끝까지 구해야 하는 prime number와 factor의 범위는 n/factor로 더욱 작아지므로 결국 뒤에서 찾는 것 보다 더 빨리 찾을 수 있다.
- 시간 복잡도 역시 (사실상) O(n)으로 결정될 수 있다. (원래 복잡도는 O(sqrt(n))이다.) n보다 작은 factor를 찾아낸다면 n은 급격히 줄어들지만 최악의 경우의 factor는 자기 자신인 n일 수 있으므로 결국 factor를 찾아내는 과정은 최대 n이다.

## Review

- 이 문제에서 사용하는 VB.NET 만의 특징은 없다.
- 어차피 문법은 VB.NET 이지만 .NET Core를 사용하므로 namespace가 같다. 따라서 C#에서 했던 짓이 거의 된다는 느낌으로 하면 들어맞는다.
- 대표적인 예가 Math.Sqrt() 사용할 때.