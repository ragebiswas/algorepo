import math
import sys

def numdivs(n):
    divs = []
    for i in range(1, (int)(math.sqrt(n)) + 1):
        if n % i == 0 and i not in divs:
            divs.append(i)
            if i != n/i:
                divs.append(n/i)
    return len(divs)
    

n = 0
i = 1
    
while(True):
    n = n+i
    i = i+1
    x = numdivs(n)
    if x >= 500:
        print n, ":", x
        sys.exit(1)
    