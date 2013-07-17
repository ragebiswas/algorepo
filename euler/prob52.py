import sys

lo = 10

while True:

  hi = int(lo*10/6)  
  print 'Trying:', lo, '-', hi
  n = lo
  
  while n < hi:
    n += 1
    s = set(str(n))
    for i in range(2, 7):
      t = n*i
      if set(str(t)) != s:
        break
    if i == 6:
      print 'Found: ', n
      sys.exit(0)        
  
  lo *= 10