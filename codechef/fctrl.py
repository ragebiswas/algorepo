n = int(raw_input())

def z(n):
  c = 0
  d = 1
  while True:
    d = d*5
    t = n/d
    if t == 0:
      break
    c += t  
  return c
  



while n > 0:
  x = int(raw_input())
  print z(x)
  n = n-1
  