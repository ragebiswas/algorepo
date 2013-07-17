import sys
h = 144

while True:
  t = 2*h*(2*h-1)
  p = h
  while True:
    pn = 3*p*p - p
    if pn == t:
      print 't =', t/2
      print 'h =',h, 'p =',p 
      sys.exit(0)
    elif pn > t:
      break
    else:
      p += 1
  h += 1  

