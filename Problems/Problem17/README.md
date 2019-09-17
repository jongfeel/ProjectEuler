# Problem 17

## Number letter counts

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

**NOTE**: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

Korean: [http://euler.synap.co.kr/prob_detail.php?id=17](http://euler.synap.co.kr/prob_detail.php?id=17)\
English: [https://projecteuler.net/problem=17](https://projecteuler.net/problem=17)

## System Requirement

- Tool: Visual Studio Code
- SDK: Java SDK 12.0.2 2019-07-16
- Language: Java

## Test - bash

```bash
javac Problem17.java
```

```bash
java Problem17
```

## Test - Visaul Studio Code

- Open folder "Problem17" by Visual Studio Code
- Check out settings - launch.json
- Press F5 to debug start

## Solve

영어로 된 숫자를 조금 생각해 보면 정해져 있는 단어를 쓰므로 단어를 몇 개 정하고 조합을 하는 경우로 생각해 본다. 단순히 1 ~ 1000까지의 for문을 돌려가면서 구해야 할 거 같지만, 더 잘 생각해 보면 필요 없을 수도 있다. 즉 코드를 짜지 않고 그냥 산수 계산만으로 가능하다.

1. 우선 1 ~ 9 까지는 정해져 있는 단어이므로 미리 계산한다.
    - one, two, three, four, five, six, seven, eight, nine
    - 3 + 3 + 5 + 4 + 4 + 3 + 5 + 5 + 4 = **36**
2. 10 ~ 19 까지 역시 정해져 있으므로 역시 미리 계산해 본다.
    - ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen
    - 3 + 6 + 6 + 8 + 8 + 7 + 7 + 9 + 8 + 8 = **70**
3. 20 ~ 99 까지의 패턴을 분석해 보면
    - 각 10단위 글자를 계산해 본다.
        - twenty, thrity, forty, fifty, sixty, seventy, eighty, ninety
            - 6 + 6 + 5 + 5 + 5 + 7 + 6 + 6 = 46
        - 20 ~ 29가 열번 반복되고 30 ~ 39도 마찬가지다. 즉 각 10단위마다 같은 글자가 열번 반복되므로
            - 6 * 10 + 6 * 10 + ... + 6 * 10 = 460
        - Distributive property(분배법칙)로 묶으면
            - 10 * (6 + 6 + 5 + 5 + 5 + 7 + 6 + 6) = 460
    - 10단위를 제외하고 1 ~ 9의 숫자는 이미 구했다. 21 ~ 29에 사용되고 30 ~ 39에서 또 사용되므로 총 여덞번 반복하는 걸로 계산한다.
        - 36 * 8 = 288
    - 460 + 288 = **748**의 결과를 얻을 수 있다.
4. 100 ~ 999
    - 100을 뜻하는 hundred는 7글자이다. 그런데 단독으로 쓰지 않고 앞에 숫자를 붙여 one hundred로 쓴다. 십과 일의 자리를 제외하고 백단위만 계산해 보면(100, 200, 300, 400, 500, 600, 700, 800, 900) => 1 ~ 9가 쓰이고 hundred도 아홉번 쓰인다. 1 ~ 9는 36으로 미리 구해 놨으므로 hundred가 아홉번 쓰이는 걸 추가로 계산한다.
        - 36 + (7 * 9) = 99
    - 모든 hundred 앞에는 1 ~ 9의 숫자가 쓰이는데 각 100번씩 쓰인다. 100의 one이 100번, 200의 two가 100번이다. 그런데 100단위 숫자에서 쓰는 값은 위에서 이미 구해 놨으므로 99번씩 으로 계산한다.
        - 36 * 99 = 3564
    - 이후 숫자는 hundred and가 항상 붙어서 나오므로 10글자로 계산하면 되고 백단위씩 총 99번 반복된다. 또 그 이후의 수는 1 ~ 9, 10 ~ 19, 20 ~ 99에서 계산한 숫자와 같다. 이게 900단위 까지 가야 하므로 아홉번 더 반복한다. 그러면 아래와 같이 산수가 가능하다.
        - ((10 * 99) + 36 + 70 + 748) * 9 = 16596
    - 99 + 3564 + 16596 = **20259**
5. 1000
    - one thousand는 **11**글자이다.

## Result

- 1, 2, 3, 4, 5에서 구한 값을 모두 더해본다.
- 36 + 70 + 748 + 20259 + 11 = 21124

## Review

어떻게 하다 보니 코드 없이 패턴 분석으로만 문제를 해결하게 됐다. 사실 세상의 문제는 소프트웨어로 만들 가치가 있을 때 소프트웨어가 필요한 것이므로 다른 방법으로도 해결이 가능하다는 사실은 어떤 면에서 더 즐거움을 주는 것 같다.
