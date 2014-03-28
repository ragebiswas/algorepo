def parr(arr):
  print ' '.join(str(t) for t in arr)
    
m = int(raw_input())
arr = [int(i) for i in raw_input().strip().split()]
i = m - 2
t = arr[m - 1]

while i >= 0:
  if arr[i] > t:
    arr[i + 1] = arr[i]
  else:
    break
  parr(arr)
  i -= 1

arr[i + 1] = t
parr(arr)

