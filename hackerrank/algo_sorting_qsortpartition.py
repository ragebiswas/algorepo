#!/bin/python
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
    
    for r in ret:
      print r,

m = input()
ar = [int(i) for i in raw_input().strip().split()]
partition(ar)