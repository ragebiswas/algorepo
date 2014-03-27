# Enter your code here. Read input from STDIN. Print output to STDOUT
n = int(raw_input())
sorted = [[] for i in range(n+1)]

for i in range(0, n):
  t = raw_input().split()
  d = int(t[0])
  if i >= n/2:
  	sorted[d].append(t[1])
  else:
  	sorted[d].append('-')
 
for i in range(0, n+1):
  if sorted[i] != []:
    for j in sorted[i]:
      print j,