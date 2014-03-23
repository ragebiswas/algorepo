import math

def is_square(n):
  f = float(math.sqrt(n))
  fi = int(f)
  if fi*fi == n:
    return True
  return False
   

ncases = int(raw_input())
for i in range(0, ncases):
  n = int(raw_input())
  if is_square(5*n*n+4) or is_square(5*n*n-4):
    print 'IsFibo'
  else:
    print 'IsNotFibo'