import math
import sys

def len(n):
    return (int)(math.log10(n)+1.0)
    

n1 = 1
n2 = 1
c = 1

while(True):
    tmp = n2
    n2 = (n1+n2)
    n1 = tmp
    c = c+1
    if(len(n1) == 1000):
        print c, ":", n1
        sys.exit(0)
    