#!/bin/python
def parr(ar):
    for r in ar:
      print r,
    print

def partition(ar):   
    ret1 = []
    ret2 = []
    pivot = ar[0]
    for v in ar[1:]:
      if v <= pivot:        
        ret1.append(v)
      else:
        ret2.append(v)
    ret = ret1 + [pivot] + ret2
    return ret, len(ret1)

def qSort(ar, i, j):
  if len(ar[i:j]) <= 1:
    return ar[i:j]
  ret, p = partition(ar[i:j])
  ar = ret
  ret =  qSort(ar, 0, p) + [ar[p]] + qSort(ar, p+1, len(ar))
  parr(ret)
  return ret
  
  
  
def quickSort(ar): 
  ar = qSort(ar, 0, len(ar))
    

m = input()
ar = [int(i) for i in raw_input().strip().split()]
quickSort(ar)
