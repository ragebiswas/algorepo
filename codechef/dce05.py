import sys


def odd(n):
  return n % 2

def process(n):
  l = [ i for i in range(1, n+1) ]
  print n, "->",
  while len(l) > 1:
    l2 = [ l[i] for i in range(len(l)) if i % 2 == 1]
    l = l2
  print l[0]





nc = int(raw_input())

for i in range(1, 101):
  process(i)