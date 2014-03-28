def parr(arr):
  print ' '.join(str(t) for t in arr)
    
m = int(raw_input())
arr = [int(i) for i in raw_input().strip().split()]

for i in range(1, m):
  t = arr[i]
  j = i - 1
  while j >= 0:
    if arr[j] > t:
      arr[j + 1] = arr[j]
    else:
      break
    j -= 1
  arr[j + 1] = t
  parr(arr)
  
