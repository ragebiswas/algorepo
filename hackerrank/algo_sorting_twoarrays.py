ncases = int(raw_input())
for i in range(0, ncases):
  n, k = map(int, raw_input().split())
  arr1 = map(int, raw_input().split())
  arr2 = map(int, raw_input().split())
  arr1.sort()
  arr2.sort(reverse=True)
  ans = 'YES'
  for j in range(0, n):
    if arr1[j] + arr2[j] < k:
      ans = 'NO'
      break
  print ans