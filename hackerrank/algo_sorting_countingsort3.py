# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import Counter
n = int(raw_input())
arr = []
for i in range(0, n):
  arr.append(int(raw_input().split()[0]))

c = Counter(arr)
t = c[0]
print t,
for i in range(1, 100):
  t += c[i]
  print t,