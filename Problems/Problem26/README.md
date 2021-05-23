# Problem 26

## Reciprocal cycles

A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

1/2	= 	0.5\
1/3	= 	0.(3)\
1/4	= 	0.25\
1/5	= 	0.2\
1/6	= 	0.1(6)\
1/7	= 	0.(142857)\
1/8	= 	0.125\
1/9	= 	0.(1)\
1/10	= 	0.1\

Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

Korean: [http://euler.synap.co.kr/prob_detail.php?id=26](http://euler.synap.co.kr/prob_detail.php?id=26)\
English: [https://projecteuler.net/problem=26](https://projecteuler.net/problem=26)

## Analysis

문제의 예시에서 한가지 힌트를 얻었는데, 7의 경우에는 6자리로 순환이 된다. 1을 7자리까지 나누다 보면 떨어지는 숫자가 6자리에서 맞아 들어가는 경우로 생각을 해볼 수 있다.

또, 2, 4, 5, 8, 0(10) 같은 수는 순환이 생기지 않는 수이므로 패스할 수 있다.

결국 3, 6, 7, 9로 끝나는 수 중에 무한 순환이 없는 수 중 하나가 longest recurring cycle을 갖는 수일 가능성이 높게 된다.

더 나가서 13, 17, 19의 경우 python으로 가볍게 나눗셈 체크를 해 보면 유력한 후보가 누구인지 발견할 수 있다.

1/13 = 0.07692307692307693\
1/17 = 0.058823529411764705\
1/19 = 0.05263157894736842

float 계산이 여기까지 된다.

- 13의 경우는 769230 으로 6자리로 순환이 되는게 확인된다.
- 17 부터는 float의 자리수가 짤리지만 아마 더 확장해 본다면 17은 16자리, 19는 18자리로 순환할 것이다.
- decimal로 확인해 보면 17은 16자리, 19는 18자리로 순환하는 걸 확인할 수 있다.
  - 17일 때: Decimal('**5.882352941176470**588235294118E+38')
  - 19일 때: Decimal('**5.26315789473684210**5263157895E+38') 

공교롭게도 이런 순환을 발생시키는 수는 소수라는 것도 확인 가능하다.

그러면 대략 아래와 같은 수라는 결론에 도달할 수 있다.

- 긴 순환을 만드는 수는 소수이며 그 순환은 소수 보다 작은 길이의 순환 혹은 소수보다 1이 작은 길이의 순환을 만든다.
- 1000 까지의 수 중에 가장 긴 순환을 가지는 수이므로 이 수보다 작은 소수인 997 부터 검사해 보기 시작하면 997이 아닐까?
- 하고 넣어봤지만 답이 아니라고 한다.
- 그래봤자 예상에는 950이 넘지 않는 소수 중에 답이 있을 확률이 높으므로 아래 후보 중에 하나가 답이라고 자신할 수 있다.
- 953, 967, 971, 977, 983, 991

## Design

### Get prime number

소수를 만드는 방법은 이미 [Problem3](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem3)에서 [IsPrime](https://github.com/jongfeel/ProjectEuler/blob/ffc11ed47c343586fd0408778afe477068bf64f5/Problems/Problem3/Problem3/Program.vb#L28-L35) 함수를 만들었으므로 이번 문제에서 풀어볼 C# 버전으로 바꿔서 적용해본다.

### Make recurring cycle

C#에는 [System.Numerics.BigInteger](https://docs.microsoft.com/en-us/dotnet/api/system.numerics.biginteger?view=net-5.0)를 지원하므로 이걸 사용해서 계산을 시도해 본다.

또 float number의 자리 수를 구하기 어려우므로

- pow(10000000000, 100)로 길이가 1000인 숫자 생성
- 소수로 나눠서 나온 몫의 값 중 대략 5자리 이상 겹치는 순환 수를 찾음
- 만약 찾아내면 그 전 몫의 자리수 까지가 소수보다 하나 작은 수의 순환 수를 가지는 소수이다!

이쯤되면 python으로 하면 그냥 결과가 나올 것 같다.

``` python
print(pow(10000000000, 100) // 991)
print(pow(10000000000, 100) // 983)
print(pow(10000000000, 100) // 977)
print(pow(10000000000, 100) // 971)
print(pow(10000000000, 100) // 967)
print(pow(10000000000, 100) // 953)
```

하지만 C#으로 풀어야 하므로 대략 아래와 같은 작전으로 풀어본다.
pow(10000000000, 100)을 소수로 나눈 몫의 값이 순환이 일어나는 시점의 index가 소수보다 1이 작은 수인지 판별하는 코드이다. 

``` csharp
BigInteger dividend = BigInteger.Pow(10000000000, 100);
for (int i = 1000; i > 1; i--)
{
    if (IsPrime(i))
    {
        BigInteger result = BigInteger.Divide(dividend, i);
        
        string resultString = result.ToString();
        string recurringCycle5digit = resultString.Substring(0, 5);

        int recurringCycle = resultString.IndexOf(recurringCycle5digit, 5, resultString.Length - 5);

        if (recurringCycle + 1 == i)
        {
          Console.WriteLine(i);
          break;
        }
    }
}
```

그냥 md 파일로 코딩했는데 다 짜버린 것 같다...
실제 코딩은 다음에 하고 변경 사항 있으면 문서 업데이트 하면 될 듯.

## Ready to development environment

- [Visual Studio Code 1.56.2](https://code.visualstudio.com/)
  - Add extension: C# for Visual Studio Code
- SDK: [.NET 5 5.0.203](https://dotnet.microsoft.com/download/dotnet/5.0)

## Build and run

Change directory from git root

``` bash
cd Problems/Problem26
```

and build and run

``` bash
dotnet run
```

Run program after build

```bash
/bin/Debug/net5.0/Problem26.exe
```

## Build and run - Visaul Studio Code

- Open folder "Problem26" by Visual Studio Code
- Check out settings: launch.json and tasks.json
- Press Ctrl + Shift + B to Build
- Press F5 to debug start