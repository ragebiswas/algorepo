s = ""
MAX = 100
i = 1
j = 0
arr = [ 1, 10, 100, 1000, 10000, 100000, 1000000 ]


prod = 1

while True:
  if len(s) >= arr[j]:
    print arr[j], "=>", s[arr[j]-1]
    prod *= int(s[arr[j]-1])
    j += 1
    if j >= len(arr):
      break
  s += str(i)
  i += 1
  
print 'Prod = ', prod