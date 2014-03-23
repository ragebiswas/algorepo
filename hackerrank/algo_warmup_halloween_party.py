# Enter your code here. Read input from STDIN. Print output to STDOUT
ncases = int(raw_input())
for i in range(0, ncases):
  n = int(raw_input())
  nby2 = int(n/2)
  print nby2 * (n-nby2)