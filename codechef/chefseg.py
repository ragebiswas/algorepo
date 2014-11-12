import math

nc = int(raw_input())
for i in range(0, nc):
    n, k = map(int, raw_input().split())

    # Step 1: calculate denominator - next power of 2
    dn = math.log(k, 2) + 1
    dn = int(pow(2, int(dn)))

    # Step 2: calculate numerator 
    lp = int(math.log(k, 2))
    lp = int(pow(2, lp))
    nm = (k - lp) * 2 + 1

    # Step 3: answer
    ans = float(nm * n)/dn
    print '%.10f' % ans

