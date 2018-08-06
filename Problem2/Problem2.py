
def Fibonacci(untilNumber):
    a,b = 1,2
    while True:
        if a > untilNumber:
            break
        yield a
        a, b = b, a + b

print(sum(fibonicciNumber for fibonicciNumber in Fibonacci(4000000) if fibonicciNumber % 2 == 0))