import sys, array

file = open(sys.argv[1])
num = int(next(file))
arr = array.array('i', [-1] * num)

def find(n):
  if(arr[n] < 0):
    return n
  else:
    t = find(arr[n])
    arr[n] = t
    return arr[n]

def union(n1, n2):
  n1 = find(n1)
  n2 = find(n2)
  if(arr[n2] < arr[n1]):
    arr[n1] = n2
  else:
    if(arr[n1] == arr[n2]):
      arr[n1] = arr[n1]-1
    arr[n2] = n1


y = n = 0
for line in file:
  sp = line.split()
  c = sp[0]
  p1 = int(sp[1])
  p2 = int(sp[2])

  if c == 'c':
    if find(p1) != find(p2):
      union(p1, p2)
  else:
    if find(p1) == find(p2):
      y += 1
    else:
      n += 1

print ("%s,%s") % (y,n)
