#!/usr/bin/py

def getsmallestlargerthan(arr, n):
  low = 0
  high = len(arr) - 1
  while low != high:
    mid = (low + high) / 2
    if arr[mid] < n:
      low = mid + 1
    else:
      high = mid
  return high, arr[high]

# Head ends here
def pairs(a,k):
    #a contains array of numbers and k is the value of difference
    a.sort()
    print a
    answer = 0
    for i in range(0, len(a) - 1):
      p, v = getsmallestlargerthan(a, a[i] + k)
      print 'ai,p,v=', a[i], p, v
      if v >= a[i]:
        answer += len(a) - p - 1
    return answer
  
# Tail starts here
if __name__ == '__main__':
    a = map(int, raw_input().strip().split(" "))
    _a_size=a[0]
    _k=a[1]
    b = map(int, raw_input().strip().split(" "))
    print pairs(b,_k)
