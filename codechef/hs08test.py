x, y = raw_input().split()

X = int(x)
Y = float(y)

if float(X) + 0.5 > Y:
  print Y
elif X % 5 != 0:
  print Y
else:
  print Y-(float(X) + 0.5)