arr = []

def solve(startpos):
  if startpos >= len(arr) - 1:
    return 0
  maxpos = 0
  maxprice = 0
  for x in range(startpos, len(arr)):
    if arr[x] > maxprice:
      maxprice = arr[x]
      maxpos = x
  cost = 0
  numshares = 0
  for x in range(startpos, maxpos):
    cost += arr[x]
    numshares += 1
  profit = numshares * arr[maxpos] - cost
  return profit + solve(maxpos + 1)
  


ncases = int(raw_input())
for i in range(0, ncases):
  n = int(raw_input())
  arr = map(int, raw_input().split())
  print solve(0)