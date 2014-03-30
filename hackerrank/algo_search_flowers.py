#!/bin/python
n, k = map(int, raw_input().split())
costs = map(int, raw_input().split())
costs.sort(reverse=True)
level = 0
tot = 0
ans = 0
while tot < n:
  for i in range(0, k):
    ans += (level + 1) * costs[tot]
    tot += 1
    if tot >= n:
      break
  level += 1
  
print ans

