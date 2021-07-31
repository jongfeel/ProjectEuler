# Problem 28

## Number spiral diagonals

Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

<span style="color:red">**21**</span> 22 23 24 <span style="color:red">**25**</span>\
20 &nbsp; <span style="color:red">**7**</span> &nbsp; 8 &nbsp; <span style="color:red">**9**</span> 10\
19 &nbsp; 6 &nbsp; <span style="color:red">**1**</span> &nbsp; 2 11\
18 &nbsp; <span style="color:red">**5**</span> &nbsp; 4 &nbsp; <span style="color:red">**3**</span> 12\
<span style="color:red">**17**</span> 16 15 14 <span style="color:red">**13**</span>

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

Korean: [http://euler.synap.co.kr/prob_detail.php?id=28](http://euler.synap.co.kr/prob_detail.php?id=28)\
English: [https://projecteuler.net/problem=28](https://projecteuler.net/problem=28)

## Selected programming language

Shell, 2020 Top languages over the years 9th.

## Analysis

각 대각선 방향으로 arithmetic progression(수열)의 규칙을 찾아본다.

### Top-right

1, 9, 25, ...

더 나열해 본다면 아마 49, 81일 것이다.

Pow(1, 2), Pow(3, 2), Pow(5, 2), Pow(7, 2), ...

이런 규칙을 갖는 수열을 찾을 수 있다.

1001 x 1001 크기의 matrix 까지의 수열의 합이므로 각 대각선 수열의 개수는 2n - 1의 규칙으로 찾을 수 있다.

따라서 1001까지 크기라면 수열 항의 마지막은 Pow(501, 2)일 것이다.

이걸 식으로 만들어 보면

- n은 1 <= n <= 501 일 때
- Pow(2n - 1, 2)

를 만족한다.

### Top-left

1, 7, 21, ...

어떤 규칙을 찾기가 어려워 보인다. 더 숫자를 나열해 보면

1, 7, 21, 43, 73, 111, ...

규칙이 없어 보인다. common difference(공차)를 나열해 보면 8씩 많은 규칙 정도는 있는 것 같다.

6, 14, 22, 30, ...

그런데 Top-right 수열과 함께 나열해 보면

- 1, 9, 25, 49, 81, ...
- 1, 7, 21, 43, 73, ...

이렇게 되고 잘 보면 Top-right와 비교해 봤을 때 2, 4, 6, 8, ... 만큼 작은 수의 나열이라는 걸 알 수 있다. 공차가 2인 것이다!

그래서 Top-Left의 식에서 공차 2만큼이 작은 수열로 볼 수 있으므로 다음과 같은 식으로 만들어 볼 수 있다.

- n, 1 <= n <= 501
- Pow(2n - 1, 2) - 2(n - 1)

### Bottom-left, Bottom-right

마찬가지로 살펴보면

- Bottom-left는 Top-left에서 공차가 2만큼 작은 수열
- Bottom-right는 Bottom-left에서공차가 2만큼 작은 수열

을 알 수 있다.

그래서 각각 또 아래와 같은 식을 만들어 볼 수 있다.

Bottom-left

- n, 1 <= n <= 501
- Pow(2n - 1, 2) - 2(n - 1) - 2(n - 1)

Bottom-right

- n, 1 <= n <= 501
- Pow(2n - 1, 2) - 2(n - 1) - 2(n - 1) - 2(n - 1)

### Sum of 4 arithmetic progression

이제 모든 식을 다 더해보면 합을 구할 수 있게 된다.

- Pow(2n - 1, 2) + Pow(2n - 1, 2) - 2(n - 1) + Pow(2n - 1, 2) - 2(n - 1) - 2(n - 1) + Pow(2n - 1, 2) - 2(n - 1) - 2(n - 1) - 2(n - 1)
- 4Pow(2n - 1, 2) - 12(n - 1)
- 4(Pow(2n - 1, 2) - 3(n - 1))

로 식 유도가 가능하다.

### Test

- n == 2 일 때 각 대각선 방향의 두번째 수열의 값인 3, 5, 7, 9를 더한 24의 값이 나오면 된다.
  - 4(Pow(3, 2) - 3)
  - 24
- n == 3 일 때, 각 대각선 방향의 세번째 수열의 값인 13, 17, 21, 25를 더한 76이 나오면 된다.
  - 4(Pow(5, 2) - 6)
  - 4 * 19
  - 76

이게 이 식을 n == 501이 될 때 까지 loop문을 돌면서 계속 더해 나가면 답을 얻을 수 있다.

## Design



## Ready to development environment

- Use git bash on windows
- [Git for windows 2.32.0.windows.1](https://git-scm.com/downloads)

## Build and run

Change directory from git root

``` bash
cd Problems/Problem28
```

and run

``` bash
./problem28.sh
```