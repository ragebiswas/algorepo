ncases = int(raw_input())
for i in range(0, ncases):
  n = int(raw_input())
  h = 1
  for j in range(1, n + 1):
    if j % 2 == 1:
      h *= 2
    else:
      h += 1
  print h