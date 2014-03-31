def primes_sieve(limit):
    limitn = limit+1
    not_prime = set()
    primes = []

    for i in range(2, limitn):
        if i in not_prime:
            continue

        for f in range(i*2, limitn, i):
            not_prime.add(f)

        primes.append(i)

    return primes
    
import math

dp = [0] * 41 
dp[1] = 1
dp[2] = 1
dp[3] = 1
dp[4] = 2
for i in range(5, 41):
  dp[i] = dp[i-1] + dp[i-4]
  
sieve = primes_sieve(dp[40])

ncases = int(raw_input())
for i in range(0, ncases):
  n = int(raw_input())
  x = dp[n]
  ans = 0
  for y in sieve:
    if y <= x:
        ans += 1
    else:
        break

  print ans