import math

def isprime(startnumber):
    startnumber*=1.0
    for divisor in range(2,int(startnumber**0.5)+1):
        if startnumber/divisor==int(startnumber/divisor):
            return False
    return True

y = 600851475143
x = int(math.sqrt(y))

for i in range(2, x+1):
    if(y % i == 0 and isprime(i)):
        print i
        