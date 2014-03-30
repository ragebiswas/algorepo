from collections import Counter

n = int(raw_input())
arr1 = map(int, raw_input().split())
m = int(raw_input())
arr2 = map(int, raw_input().split())

c1 = Counter(arr1)
c2 = Counter(arr2)

ans = []
for key in c2.keys():
  if c1[key] < c2[key]:
    ans.append(key)

ans.sort()
print  ' '.join(map(str, ans))