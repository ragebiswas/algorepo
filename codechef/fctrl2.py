import sys

fact = []
fact.append(1)
fact.append(1)

for i in range(2,101):
    fact.append(i*fact[i-1])

l = sys.stdin.readlines()
c = int(l[0])

for i in range(1,c+1):
    print fact[int(l[i])]