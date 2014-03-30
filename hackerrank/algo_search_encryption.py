import math, sys
s = raw_input().strip()
l = len(s)
r = int(math.sqrt(l))
c = r
if r*r < l:
  c += 1
if r*c < l:
  r += 1 
arr = [""] * r
t = 0
for i in range(0, r):
  for j in range(0, c):
    arr[i] += s[t]
    t += 1
    if t >= l:
      break
      
t = 0

for i in range(0, c):
  for j in range(0, r):
    if i < len(arr[j]):
      sys.stdout.write(arr[j][i])
  print ' ',
