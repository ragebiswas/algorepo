n = int(raw_input())
k = int(raw_input())
candies = [int(raw_input()) for i in range(0,n)]
candies.sort()
min_diff = 1000000001

for i in range(0, n-k+1):
  min_diff = min(min_diff, candies[i+k-1] - candies[i])
  
print min_diff