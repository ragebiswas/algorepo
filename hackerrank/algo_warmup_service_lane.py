# Enter your code here. Read input from STDIN. Print output to STDOUT
n, t = map(int, raw_input().split())
width = map(int, raw_input().split())

for i in range(0, t):
  start, end = map(int, raw_input().split())
  minAvl = 4
  for j in range(start, end + 1):
    if width[j] < minAvl:
      minAvl = width[j]
  print minAvl