# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import Counter
n = raw_input()
arr = map(int, raw_input().split())
c = Counter(arr)
for i in range(0, 100):
  print c[i],