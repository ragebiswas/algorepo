n = int(raw_input())
arr = map(int, raw_input().split())
arr.sort()
mindiff = 100000000
ans = []
for i in range(1, n):
  if arr[i] - arr[i-1] < mindiff:
    mindiff = arr[i] - arr[i-1]
    l = []
  if arr[i] - arr[i-1] == mindiff:
    l.append(arr[i-1])
    l.append(arr[i])
print ' '.join(str(i) for i in l)