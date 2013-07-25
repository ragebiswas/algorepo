n = int(raw_input())
for i in xrange(0, n):
  s = str(raw_input())
  n1 = s.split()[0][::-1]
  n2 = s.split()[1][::-1]
  sum = int(n1) + int(n2)
  sum = str(sum)[::-1]
  print int(sum)


