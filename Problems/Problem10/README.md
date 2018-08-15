# Problem 10

## Summation of primes

> The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.\
Find the sum of all the primes below two million.

Korean: [http://euler.synap.co.kr/prob_detail.php?id=10](http://euler.synap.co.kr/prob_detail.php?id=10)\
English: [https://projecteuler.net/problem=10](https://projecteuler.net/problem=10)

## System Requirement

- Tool: Visual Studio Community 2017
- Language: Visual Basic .NET
- Framework: .NET Core 2.0
- Visual Studio Project: .NET Core Console App

## .NET Core 2.1 SDK Downloads (If you do not want Visual Studio Community 2017)

- [https://www.microsoft.com/net/download](https://www.microsoft.com/net/download)

## Test - bash

Change directory git root: /Problem10
and compile

```bash
dotnet build
```

Run

```bash
dotnet run
```

## Test - Visaul Studio Community 2017

- Open visual studio solution file "Problem10.sln" by Visual Studio Community 2017
- Check out install packages - .NET Core 2.0 and Visual Basic Environment
- Press F5 to debug start

## Solve

- 기존에 Problem3에서 썼던 IsPrime 함수를 사용한 방식으로 쉽게 될 것 같았으나
- 2,000,000만 까지 loop를 돌게 되면 엄청나게 오랜 시간이 걸리게 되므로 다른 방법을 써야 한다.
- 이제 여기까지 오면 에라토스테네스의 체를 사용해서 prime number를 구하는게 맞는 방법인 것 같은 느낌이 든다. (느낌이 아니라 팩트인듯)
- 위키 참조: [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)
- 위 링크에 pseudo 코드 까지도 나와 있으므로 이 방법으로 코드를 그대로 구현하면 된다.
- 하지만 약간 방식을 바꿔서 boolean array를 true -> false로 바꾸는 방식 말고
- 처음부터 0 ~ 2000000 숫자를 넣어 놓은 리스트를 만들고 에라토스테네스의 체에 걸린 수는 그 값을 0으로 바꾸는 식으로 한다. 헷갈리지 않게 index와 item의 값이 같게 만들어 준다. primes(0) = 0, primes(10) = 10, ...
  - 이유: VB.NET의 List.Sum() 함수를 호출하는 것으로 List item 값들의 합을 쉽게 구할 수 있으므로 소수가 아닌 건 0으로 세팅해 놓으면 자연스럽게 소수인 수들의 합이 구해지게 된다.
- Primes(1) = 0: 1은 소수가 아니므로 처음부터 0으로 세팅하고 시작한다.
- 첫 For문 해석: For문을 돌 떄 구하려는 값의 Sqrt 까지만 해도 소수를 구할 수 있다는 건 지난 문제에서도 써먹었으니 다시 사용한다.
- 0이 아닌 값 체크: List에 값이 0으로 되어 있는 index는 소수가 아닌 수이므로 (체에 걸러지는 수) 0이 아닌 값이라면 이후 값이 소수인지 판별하게 For문을 돌려본다. 이게 에라토스테네스의 체 아이디어이다.
- 두번째 For문 해석: 해당 숫자의 배수들은 모두 소수가 아닌 수 이므로 그 두배가 되는 index의 수 부터 index 배수 만큼을 모두 0으로 세팅한다.
  - 예) index가 2인 경우: innerIndex는 index * 2 이므로 4부터 시작한다. innerIndex=4 (값 4) 부터 해서 index 배수 만큼 for문을 돌게 되므로 결국 4, 6, 8, 10, ...의 index를 가진 값은 모두 0으로 세팅된다.
  - 예2) index가 3인 경우: innerIndex는 index * 2 이므로 6부터 시작한다. innerIndex=6 (값 6) 부터 해서 index 배수 만큼 for문을 돌게 되므로 6, 9, 12, 15, ...의 index를 가진 값은 모두 0으로 세팅된다. 이미 0으로 세팅되어 있는 index인지 판별할 필요 없이 쭉 세팅한다.
  - 이렇게 2, 3, 5, 7 까지만 해도 거의 모든 소수가 아닌 수들은 걸러지게 된다.

## Language Review

- VB.NET에서 인덱스 접근이 []이 아니라 ()인 건 꽤나 적응이 안된다. 다른 언어에 많이 익숙해져서 그런지 index 접근이 아니라 함수를 호출하고 파라미터로 int 값을 넘겨주는 것처럼 보인다. 그것도 계속.
- VB.NET의 함수 파라미터 쓰는 방법이 C#이나 javascript등 기타 다른 언어에서 쓰던 lambda 형태와 많이 다르다. 오히려 조금 더 직관적인 것 같기도 한데, Function이라는 키워드에 파라미터를 적고 그 이후에 function body를 적으면 그냥 함수를 구현하는 게 된다. "=>" 요 키워드 마저도 생략된 느낌.