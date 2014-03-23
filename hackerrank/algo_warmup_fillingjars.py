# Enter your code here. Read input from STDIN. Print output to STDOUT
n, o = map(int, raw_input().split())
t = 0
for i in range(0, o):
  a, b, q = map(int, raw_input().split())
  t += ((b - a + 1)* q) 
print int(t/n)
