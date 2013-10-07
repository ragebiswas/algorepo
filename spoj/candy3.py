#
# Problem: http://www.spoj.com/problems/CANDY3/
# Category: Simple Coding
#
nc = int(raw_input())

while nc != 0:
    y = raw_input()
    nc -= 1
    n = 0
    tot = 0
    n = int(raw_input())
    tmp = n
    while tmp != 0:
        tot += int(raw_input())
        tmp -= 1
    if tot % n == 0:
        print 'YES'
    else:
        print 'NO'