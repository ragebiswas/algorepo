# Enter your code here. Read input from STDIN. Print output to STDOUT
nc = int(raw_input())
for i in range(0, nc):
  n = int(raw_input())
  n5 = n
  found = False
  while n5 >= 0:
    if n5 % 3 == 0 and (n - n5) % 5 == 0:
      found = True
      break
    n5 -= 1
  if not found:
    print -1
  else:
    print '5' * n5 + '3' * (n - n5)
  