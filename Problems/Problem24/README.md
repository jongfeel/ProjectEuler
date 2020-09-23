# Problem 24

## Lexicographic permutations

A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

<center>012   021   102   120   201   210</center>

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

Korean: [http://euler.synap.co.kr/prob_detail.php?id=24](http://euler.synap.co.kr/prob_detail.php?id=24)\
English: [https://projecteuler.net/problem=24](https://projecteuler.net/problem=24)

## System Requirement

- Tool: Visual Studio Code 1.49.1
- Extension: Python extension for Visual Studio Code, Python 3.8.5 64-bit
- Language: Python

## Test - bash

```bash
python Problem24.py
```

## Test - Visaul Studio Code

- Open folder "Problem24" by Visual Studio Code
- Check out settings - launch.json
- Check out python intalled path - settings.json
- Press F5 to debug start

## 0,1,2,3 permutations?

0은 1개
0,1은 01, 10으로 2개
0,1,2는 문제에서와 같이 6개
0,1,2,3은 한번 나열해 본다.

마구잡이로 나열하지 않고 lexicographic 즉 사전식으로 나열한다.

0123, 0132, 0213, 0231, 0312, 0321\
1023, 1032, 1203, 1230, 1302, 1320\
2013, 2031, 2103, 2130, 2301, 2310\
3012, 3021, 3102, 3120, 3201, 3210

총 24개가 나온다.

이 숫자... 왠지 익숙하다!

## Factorial

구글에 1, 2, 6, 24 이렇게 검색해 보면 떡하니 이게 나온다.

Factorial
https://en.wikipedia.org/wiki/Factorial

팩토리얼을 알아냈다면 이제 수학만으로 답을 찾아낼 수 있게 된다.

왜냐하면 0~9까지의 수는 10개이고 10!의 값은 3628800이라는 사실까지 알게 되었으니까.

## Factorial feature and analysis

그런데 이걸 무식하게 3628800 번을 나열해서 100만번째를 찾는건 바보같은 짓이다. 물론 100만번 나열해서 써보면 답이 나오는데 여기서는 factorial의 특징을 잘 살려 계산해 본다.

보통 n! = n * (n - 1)!의 성질을 가지고 있다. 이 조건을 만족하려면 n > 0 이다.

10! = 10 * 9! 이므로 362880을 10번 더한 값이라는 걸 알아낼 수 있다. 그럼 여기서 100만번째 수의 맨 앞자리 수를 알아낼 수 있게 된다.

0으로 시작하는 모든 permutation의 갯수 즉 나머지 9자리 수로 만든 9!의 값은 362880이 된다.
그러면 1로 시작하는 값은 362881 ~ 725760이라는 걸 알게 되고
2로 시작하는 값은 725761 ~ 1088640 이라는 사실을 유추할 수 있다.

그러므로 정답은 2로 시작하는 숫자라는 걸 알아낼 수 있다.

계속해서 그 다음 숫자는 8!을 9번 더한 값들의 나열이므로 8!인 40320을 더해 나갔을 때 몇 번째에 100만번째에 도달하는지 체크해 보면 7번째에 1008001이 되므로 7번째 숫자라는 걸 알수 있으며 2를 제외한 lexicographic 7번째 숫자는 7이라는 걸 알아낼 수 있다.

그러므로 정답은 27으로 시작하는 숫자라는 걸 알아낼 수 있다.

이 사실을 바탕으로 범위를 계속 좁혀 유추해 나가면 정답을 맞출 수 있다.
n!의 숫자만큼의 덧셈과 100만번째를 넘지 않는 조건만 생각해 보면 되는 것이다.

하지만... 이 문제는 수학 문제이기 이전에 프로그래밍으로 해결해야 하는 문제이므로 프로그래밍으로 해결해 본다. 코드가 아닌 수학으로 풀고 싶어하는 내 안의 흑염룡을 억누르자...

## python...!

오 그런데 이걸 파이썬으로 풀면 왠지 또 한줄로 코딩이 가능할 것 같다.
구글에 잠깐 python permutation이라고 검색해 보면 아래와 같은 엄청난 힌트를 얻을 수 있기 때문이다.

``` python
import itertools

print(list(itertools.permutations([1,2,3,4])))
```

여기서 조금 응용해 보면 답을 금방 찾을 수 있다. 갑자기 한줄로 코딩하고 싶어진다.