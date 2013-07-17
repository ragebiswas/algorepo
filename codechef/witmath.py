import random
def modulo(a,b,c):
  x = 1
  y = a
  while b>0:
    if b%2==1:
      x = (x*y)%c
    y = (y*y)%c
    b = b/2
  return x%c
   
def millerRabin(N,iteration):
  if N<2:
    return False
  if N!=2 and N%2==0:
    return False
   
  d=N-1
  while d%2==0:
    d = d/2
   
  for i in range(iteration):
    a = random.randint(1, N-1)
    temp = d
    x = modulo(a,temp,N)
    while (temp!=N-1 and x!=1 and x!=N-1):
      x = (x*x)%N
      temp = temp*2
     
    if (x!=N-1 and temp%2==0):
      return False
   
  return True


if __name__ == "__main__":
  nc = int(raw_input())
  for i in range(0, nc):
    n = int(raw_input())
    if n % 2 == 0 and n > 2:
      n -= 1
    while millerRabin(n, 10) == False:
      n -= 2
    print n
