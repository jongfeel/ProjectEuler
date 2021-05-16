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