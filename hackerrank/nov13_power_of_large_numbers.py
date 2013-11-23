#
# 20/20 Hack November: B'day Gift (https://www.hackerrank.com/contests/nov13/challenges/power-of-large-numbers)
# Category: Simple coding/math
# NOTE: TLE on larger inputs
#
def modpow(base, exp, modulus):
    base %= modulus
    result = 1
    while exp > 0:
        if exp & 1:
            result = (result * base) % modulus
        base = (base * base) % modulus
        exp >>= 1
    return result

M = int(1e9 + 7)
nc = int(raw_input())

for i in range(0, nc):
    b, e = map(int, raw_input().split())
    print modpow(b, e, M)