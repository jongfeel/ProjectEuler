# 이미 알고 있는 피보나치를 다른 언어의 recursive function기법으로 구현하면 시간 복잡도가 증가하는 방식이므로
# 처음부터 O(n)의 복잡도를 가지도록 python의 generator 문법으로 구현한다.

def Fibonacci(untilNumber):
    a,b = 1,2
    while True:
        if a > untilNumber:
            break
        yield a
        a, b = b, a + b

print(sum(fibonicciNumber for fibonicciNumber in Fibonacci(4000000) if fibonicciNumber % 2 == 0))