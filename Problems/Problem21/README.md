# Problem 21

## Amicable numbers

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.

Korean: [http://euler.synap.co.kr/prob_detail.php?id=21](http://euler.synap.co.kr/prob_detail.php?id=21)\
English: [https://projecteuler.net/problem=21](https://projecteuler.net/problem=21)

## System Requirement

- Tool: Visual Studio Code 1.42.1
  - Extension: C# for Visual Studio Code
- SDK: .NET Core 3.1.100
  - Download: [https://dotnet.microsoft.com/download](https://dotnet.microsoft.com/download)
- Language: C#

## Test - bash

Change directory git root: /Problem21
and compile

```bash
dotnet run
```

Run

```bash
/bin/Debug/netcoreapp3.1/Problem21.exe
```

## Test - Visaul Studio Code

- Open folder "Problem21" by Visual Studio Code
- Check out settings: launch.json and tasks.json
- Press Ctrl + Shift + B to Build
- Press F5 to debug start

## Divisors

- 약수를 구하는 것도 소수를 구하는 것부터 시작해서 알게 된 지식이기도 하고, 프로젝트 오일러를 관통하는 중요한 수학적 지식이기도 하다.

## Ready sum of divisors function

- 문제에서 220, 284의 약수를 각각 구하고 그 합을 비교를 했으므로
- SumOfDivisor(n)을 준비하는데 이건 SumOfDivisor(220) == SumOfDivior(284)가 같다는 걸 확인하기 위해서 준비 한다.
- 약수의 특성상 (그리고 소수의 특성을 포함하여) 최소 2로 나눈 몫 이상의 for문을 돌릴 필요가 없다.
- 즉, 220의 경우 자기 자신을 제외한 가장 큰 약수는 110이고 이는 소수 2로 나누어지는 몫일 때 111 ~ 220 까지의 수 중에 약수가 있는지를 찾으려고 for loop을 돌릴 필요가 없다는 뜻이기도 하다.
- 이 함수는 이런식으로 최적화를 진행한다.

## Solve

- 10000 까지 for문을 돌리고 해당 정수에 따른 약수의 합을 구하는 SumOfDivisor(i)를 호출하여 그 결과를 sum1에 담는다.
- 다시 SumOfDivisor(sum1)을 호출해 보고 그 결과를 sum2에 담는다.
- sum2 == i 인지 판단한다.
- sum2 == i 라면 i + sum2를 하고 AmicableSum 변수에 계속 누적한다.
- 문제에 d(a) = b and d(b) = a, where a ≠ b 조건이 있으므로 sum1 != sum2 조건을 걸어준다.
  - 참고로 이 숫자는 10000까지 for문 돌리면 4개가 나오는데 6, 28, 496, 8628이 나온다.
  - 이 숫자는 제외하는 조건을 추가한다.
- 최종 if문의 형태는 아래와 같게 된다.

``` csharp
if (sum2 == i && sum1 != sum2)
```

- 마지막으로 AmicableSum 값을 2로 나누어 출력해야 하는데, 이유는 220일 때 220+280을 하고 280일 때도 280+220이 되며 이후 amicalble number가 두 쌍으로 생성되므로 최종적으로 2로 나눈 값을 합으로 얻어낸다.
