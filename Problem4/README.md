# Problem 4

Korean: [http://euler.synap.co.kr/prob_detail.php?id=4](http://euler.synap.co.kr/prob_detail.php?id=4)

English: [https://projecteuler.net/problem=4](https://projecteuler.net/problem=4)

## System Requirement

- Tool: Visual Studio Code
- Language: C
- Compiler: gcc.exe (MinGW.org GCC-6.3.0-1) 6.3.0
- Use MinGW

## MinGW Download (only windows)

- [https://sourceforge.net/projects/mingw/files/](https://sourceforge.net/projects/mingw/files/)

## Test - bash

Change directory git root: /Problem4
and compile

```bash
gcc Problem4.c
```

with debugging
https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html#Debugging-Options
```bash
gcc -g Problem4.c
```

> Windows Environment Settings

> System Variable > Path > Add "C:\MinGW\bin" (Installed path)

Run

```bash
a
```

## Test - Visaul Studio Code

- Open folder "Problem4" by Visual Studio Code
- Check out settings: launch.json and tasks.json
    - launch.json
        - "miDebuggerPath": "C:/mingw/bin/gdb.exe"
        - Use MinGW installed your path
    - tasks.json
        - Use gdb debug: args[0] = "-g"
- Press F5 to debug start

## Solve

- Palindrome 구하는 아이디어는 주어진 숫자를 문자열로 변환하고, 문자열로 변환한 걸 뒤집는 문자열을 구한뒤 두 문자열이 같으면 Palindrome 이라고 생각해 볼 수 있다.
- IsPalindrome 함수는 주어진 숫자를 문자열 변환, 뒤집힌 문자열 변환, 두 문자열의 비교를 해서 0을 리턴하면 Palindrome이라고 판단한다.
- 문자열 관련 함수는 문자열 변환 sprintf, 뒤집힌 문자열로 변환 strrev, 두 문자열의 비교 strcmp를 사용했다.
- 주어진 조건은 세자리 수의 곱 중 최대값을 구하는 것이므로 세자리 수 최대값인 999 부터 시작해서 loop문을 역으로 돌려 찾아낸다.
- 다시 생각해 보면 999 ~ 900 범위 안에서 두 수를 곱하면 반드시 Palindrome이 나오게 되어 있으므로 for문의 형태는 다음과 같게 된다. for (int i=999; i>=900; i--)
- 이렇게 해서 nested for loop을 만들어 가장 먼저 IsPalindrome에 걸리는 수가 나타난다면 세자리 수의 곱 중 가장 큰 palindrome 값이라고 판단할 수 있다.

## Review

- 예전에는 몰랐는데 문자열을 뒤집어서 출력하는 strrev 함수의 존재를 알았다. 신기한건 파라미터로 넣은 문자열도 뒤집히고 리턴한 문자열 주소도 뒤집힌 원본 문자열의 주소를 준다는 것이다!
- goto를 쓰면 안된다는 압박이 언제부터 시작됐는지 몰라도, C언어에서 nested for loop을 break 하는 일이 마냥 쉽지많은 않았다. 그냥 속편하게 goto 쓰는게 깔끔한 것 같다.