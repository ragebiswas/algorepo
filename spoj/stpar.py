#
# Problem: http://www.spoj.com/problems/STPAR/
# Category: Simple coding
#

def peek(l):
    x = l.pop()
    l.append(x)
    return x

while True:
    n = int(raw_input())
    if n == 0:
        break
    list = map(int, raw_input().split())
    list.reverse()
    aux = []
    next = 1
    while True:
        if next == n:
            break
        if list and peek(list) == next:
            list.pop()
            next += 1
            continue
        if aux and peek(aux) == next:
            aux.pop()
            next += 1
            continue
        if list:
            aux.append(list.pop())
        else:
            print 'no'
            break
    if next == n:
        print 'yes'