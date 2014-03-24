import math

n = int(raw_input())
t = sum(map(int, raw_input().split())) * 2
r = int(math.sqrt(t))
if (r - 1) * r == t or r * (r + 1) == t:
    print 'YES'
else:
    print 'NO'
