import math

def IsPrime(number):
    for index in range(2, math.floor(math.sqrt(number))+1):
        if number % index == 0 and index != number:
            return False
    return True

def GetPrimeNumber(order):
    index, count = 1, 1
    while count != order:
        index += 2
        if IsPrime(index) == True:
            count += 1
            #print(count, index)
    return index

print(GetPrimeNumber(10001))