# ProjectEuler

ProjectEuler practice

## Why project euler project

이걸 안건 2017년 쯤이었던 것 같다.
영국에서 프로그래머 활동을 하는 어떤 분의 블로그를 봤는데, 꾸준히 그리고 부지런히 프로젝트 오일러의 문제 풀이를 하고 있는 걸 봤다. 그때는 막연히 나도 하면 좋겠다는 생각만 했을 뿐 실천해야 겠다는 생각은 하지 못했다. 그러다가 실천 의지를 발휘해서 하기로 했다.

### 그 분의 블로그 주소

[http://ntalbs.github.io/](http://ntalbs.github.io/)

## How to pick programming language

### Before

[TIOBE](https://www.tiobe.com/tiobe-index/) 순위 중 1 - 5위 까지의 프로그래밍 언어를 랜덤으로 하나씩 선택 해 문제를 풀고, 다음 문제는 나머지 선택되지 않은 프로그래밍 언어 중 랜덤하게 선택해서 풀어 나가는 방식

### Now

[2020 state of the octoverse](https://octoverse.github.com/)에서 Top languages over the years 순위를 참고해 1 - 10위 까지의 프로그래밍 언어를 랜덤으로 하나씩 선택해 풀고, 다음 문제는 나머지 선택되지 않은 프로그래밍 언어 중 랜덤하게 선택해서 풀어 나가는 방식.

26번 문제부터 이 방식을 채택해서 진행함.

2020 top languages over the years는 다음과 같다.

![TopLanguagesOverTheYears_2020](TopLanguagesOverTheYears_2020.png)

## Solve sequence, using software engineering

### Analysis

- 실제 알고 있어야 하는 수학적인 개념
- 수학적인 풀이 예제를 통한 구현 방식 이해

### Design

- 생각한 것을 pseudo level로 풀어야 하는 언어에 맞게 정리
- 생각했던 알고리즘이나 만들어야 하는 함수를 문서로 작성

### Coding

- 분석, 설계 했던 내용 그대로 코딩 진행
- 코딩 진행 중 생각했던 것과 달랐을 경우 문서 내용에 추가

### Test

- 실제 테스트 데이터나 코드는 작성하지 않음
- 필요에 따라 성능 테스트를 위한 시간 측정이나 logging은 진행 => 필요시 uncomment

### Maintenance

- 더 나은 구현 방식에 대한 걸 찾으면 diff 코드를 문서에 추가
- 언어별 다른 점이나 더 나은점이 있다면 역시 변경하면서 문서에 추가
- Revised할 문제가 필요하다면 별도로 새 프로젝트로 만들어서 진행

### 중요한 것!

- 절대 코딩부터 하지 말고 문제 자체를 이해한다.
- 주어진 문제 내애서 해결해야 하는 방안을 코드로 구현할 수 있게 설계를 진행하고 문서 작성을 함
- 코딩은 그 다음에 해도 늦지 않음

## Notes

- 문제를 푸는데 필요한 수학적 개념을 따로 정리
- 링크 참고: [Notes](/Notes.md)

## Problems

### [Problem 27, Quadratic primes](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem27)

- Top languages over the years 2020: picked programming is JavaScript (top 1)

### [Problem 26, Reciprocal cycles](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem26)

- Top languages over the years 2020: picked programming is C# (top 5)

### [Problem 1 revised, Multiples 3 and 5](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem1_revised)

- TIOBE index for Jun 2018, Ranking Top 1: Java

### [Problem 25, 1000-digit Fibonacci number](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem25)

- TIOBE index for October 2020, Ranking Top 1: C

### [Problem 24, Lexicographic permutations](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem24)

- TIOBE index for September 2020, Ranking Top 3: Python

### [Problem 23, Non-abundant sums](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem23)

- TIOBE index for July 2020, Ranking Top 4: C++

### [Problem 19 revised, Counting Sundays](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem19_revised)

- TIOBE index for December 2019, Ranking Top 5: C#

### [Problem 22, Names scores](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem22)

- TIOBE index for June 2020, Ranking Top 2: Java

### [Problem 21, Amicable numbers](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem21)

- TIOBE index for May 2020, Ranking Top 5: C#

### [Problem 17 revised, Number letter counts](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem17_revised)

- TIOBE index for September 2019, Ranking Top 1: Java

### [Problem 20, Factorial digit sum](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem20)

- TIOBE index for February 2020, Ranking Top 2: C

### [Problem 19, Counting Sundays](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem19)

- TIOBE index for December 2019, Ranking Top 5: C#

### [Problem 18, Maximum path sum I](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem18)

- TIOBE index for October 2019, Ranking Top 4: C++

### [Problem 17, Number letter counts](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem17)

- TIOBE index for September 2019, Ranking Top 1: Java

### [Problem 16, Power digit sum](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem16)

- TIOBE index for December 2018, Ranking Top 3: Python

### [Problem 15, Lattice paths](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem15)

- TIOBE index for September 2018, Ranking Top 2: C

### [Problem 14, Longest Collatz sequence](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem14)

- TIOBE index for July 2019, Ranking Top 4: C++

### [Problem 13, Large Sum](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem13)

- TIOBE index for January 2019, Ranking Top 5: Visual Basic .NET

### [Problem 12, Highly divisible triangular number](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem12)

- TIOBE index for September 2018, Ranking Top 1: Java

### [Problem 11, Largest product in a grid](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem11)

- TIOBE index for August 2018, Ranking Top 3: C++

### [Problem 10, Summation of primes](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem10)

- TIOBE index for August 2018, Ranking Top 5: Visual Basic .NET

### [Problem 9, Special Pythagorean triplet](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem9)

- TIOBE index for August 2018, Ranking Top 2: C

### [Problem 8, Largest product in a series](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem8)

- TIOBE index for August 2018, Ranking Top 1: Java

### [Problem 7, 10001st prime](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem7)

- TIOBE index for August 2018, Ranking Top 4: Python

### [Problem 6, Sum square difference](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem6)

- TIOBE index for August 2018, Ranking Top 3: C++

### [Problem 5, Smallest multiple](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem5)

- TIOBE index for August 2018, Ranking Top 3: C++

### [Problem 4, Largest palindrome product](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem4)

- TIOBE index for July 2018, Ranking Top 2: C

### [Problem 3, Largest prime factor](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem3)

- TIOBE index for July 2018, Ranking Top 5: Visual Basic .NET

### [Problem 2, Even Fibonacci numbers](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem2)

- TIOBE index for July 2018, Ranking Top 4: Python

### [Problem 1, Multiples 3 and 5](https://github.com/jongfeel/ProjectEuler/tree/master/Problems/Problem1)

- TIOBE index for Jun 2018, Ranking Top 1: Java
