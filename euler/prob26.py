import os

def getnextpow10(n):
  x = 10
  while x < n:
    x *= 10
  return x



def findcycle(n):
  remainders = []
  dividend = getnextpow10(n)
  remainder = 0
  cl = 0
  while True:
    #print 'div=', dividend, 'rem=', remainder
    remainder = dividend %  n
    if remainder == 0:
      return 0
    elif remainder in remainders:
      #print remainders
      return cl
    else:  
      remainders.append(remainder)
      #print 'append:', remainder
      while remainder < n:
        cl += 1
        remainder *= 10
      dividend = remainder      
      #print 'div:', dividend
  
  
  
mc = 0  
c = 0
ans = 0
for i in range(2, 1000):
  c = findcycle(i)
  if c > mc:
    mc = c
    ans = i
    
print 'Longest cycle is of number:', ans
print 'Length of longest cycle:', mc