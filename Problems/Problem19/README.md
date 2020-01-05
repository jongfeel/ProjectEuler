# Problem 19

## Counting Sundays

You are given the following information, but you may prefer to do some research for yourself.

- 1 Jan 1900 was a Monday.
- Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
- A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

Korean: [http://euler.synap.co.kr/prob_detail.php?id=19](http://euler.synap.co.kr/prob_detail.php?id=19)\
English: [https://projecteuler.net/problem=19](https://projecteuler.net/problem=19)

## System Requirement

- Tool: Visual Studio Code 1.41.1
  - Extension: C# for Visual Studio Code
- SDK: .NET Core 3.1.100
  - Download: [https://dotnet.microsoft.com/download](https://dotnet.microsoft.com/download)
- Language: C#

## Test - bash

Change directory git root: /Problem19
and compile

```bash
dotnet run
```

Run

```bash
/bin/Debug/netcoreapp3.1/Problem19.exe
```

## Test - Visaul Studio Code

- Open folder "Problem19" by Visual Studio Code
- Check out settings: launch.json and tasks.json
- Press Ctrl + Shift + B to Build
- Press F5 to debug start

## 의도 파악

- 어떻게 보면 1번 문제보다도 더 쉬운 문제라고 판단 되는데, 만약 프로그래밍 언어에서 지원하는 date 관련된 구조체, 클래스, 함수 등을 안다면 아주 쉽게 구할 수 있다.
- 하지만 이걸 일일이 계산하려면 문제에 나온 것처럼 30일, 31일인 달 따로, 윤년 따로 하는 계산을 해야 하고 사실 문제의 의도는 이것이었을지도 모른다.
- 의도가 그렇다고 하더라도 date 관련된 기능을 제공하지 않는 프로그래밍 언어는 없으므로 적극적으로 이용해 본다.

## Solve

- for문을 두번 돌린다.
  - 첫번째 for문은 1901년 부터 2000년까지 각 년도별로 도는 for문이고
  - 두번째 for문은 1월 부터 12월 까지 각 월별로 도는 for문이다.
- new Date(year, month, 1)을 생성해 주면 연, 월에 맞는 1일이 나오는데 여기서 DayOfWeek.Sunday가 맞는지 체크하고 맞으면 counting을 한다.
- 결과를 출력해 보면 올바른 결과가 나온다는 걸 확인할 수 있다.

## C#이 이번 문제에서 최초

- 놀라운건 여태까지 18문제 풀어오면서 나의 주력 언어인 C#으로 푼 문제가 한 문제도 없었다는 것이다.
- 물론 TIOBE에 C# 언어의 순위가 5위 밖으로 밀려났던 적도 있긴 했지만 그래도 한번 쯤 풀어볼만도 했을텐데 이번 문제가 처음이라는 게 신기함.