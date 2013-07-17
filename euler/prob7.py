import math, sys

def isprime(startnumber):
    startnumber*=1.0
    for divisor in range(2,int(startnumber**0.5)+1):
        if startnumber/divisor==int(startnumber/divisor):
            return False
    return True
    
numofprime = 2
thisprime = 3

while(True):
    if(isprime(thisprime)):        
        #print 'Prime number ', numofprime, ': ', thisprime
        if(numofprime == 10001):
            print 'Answer: ', thisprime
            sys.exit(0)
        numofprime = numofprime + 1    
    thisprime += 2    
        
        