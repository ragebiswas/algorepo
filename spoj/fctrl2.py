x = raw_input()
x = int(x)

def f(n):
  if n == 1:
    return 1
  else:
    return n * f(n-1)


for i in range(0,x):
  v = int(raw_input())
  print f(v)
  
