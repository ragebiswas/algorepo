#
# Problem: http://www.spoj.com/problems/ACODE/
# Category: Simple DP
#
def valid(s):
  if s.startswith('0'):
    return False
  n = int(s)
  if n >= 1 and n <= 26:
    return True

while True:
  s = raw_input().strip()
  if s == '0':
    break
  dp = [0] * len(s)
  if len(s) == 1:
    print 1
    continue

  # initialize DP
  dp[0] = 1
  if valid(s[0:2]):
    dp[1] += 1
  if valid(s[1:2]):
    dp[1] += 1

  # DP loop
  n = len(s)
  for i in range(2, n):
    if valid(s[i]):
      dp[i] = dp[i-1]
    if valid(s[i-1:i+1]):
      dp[i] += dp[i-2]

  print dp[n-1]

