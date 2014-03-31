n = int(raw_input())
scores = [0] * n
scores[0] = 1

arr = []
for i in range(0, n):
  t = int(raw_input())
  arr.append(t)
  
for i in range(1, n):
  if arr[i] > arr[i - 1]:
    scores[i] = scores[i - 1] + 1
  else:
    # adjustment loop
    scores[i] = 1
    j = i - 1
    while (j >= 0) and (arr[j] > arr[i]):
      scores[j] = max(scores[j], scores[i] + 1)
      j -= 1
      i -= 1
    
print sum(scores)
  
