#
# Problem: http://www.spoj.com/problems/PERMUT2/
# Category: Simple coding
#
while True:
    n = int(raw_input())
    if n == 0:
        break
    arr = map(int, raw_input().split())
    ans = 'ambiguous'
    for i in xrange(1, n + 1):
        p = arr[i - 1]
        if arr[p - 1] != i:            
            ans = 'not ambiguous'
            break
    print ans    