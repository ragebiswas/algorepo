# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import Counter
n = raw_input()
arr = map(int, raw_input().split())
c = Counter(arr)
for i in range(0, 100):
  if c[i] != 0:
    for j in range(0, c[i]):
      print i,