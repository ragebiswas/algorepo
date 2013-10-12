#
# Problem: http://www.spoj.com/problems/TRICOUNT/
# Category: Math (formula)
# Ref: http://mathworld.wolfram.com/TriangleTiling.html
#
nc = int(raw_input())
ans = 0
while nc != 0:
    n = int(raw_input())    
    if n % 1 == 0:
        ans = n * (n+2) * (2*n + 1)
        ans = int(ans/8)
    else:
        ans = n * (n+2) * (2*n + 1) - 1
        ans = int(ans/8)
    print ans     
    nc -= 1    