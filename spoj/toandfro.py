#
# SPOJ: To and Fro
# Category: Simple Coding
#
import sys

while(True):
    c = int(raw_input())
    if c == 0:
        sys.exit(0)
    s = str(raw_input()).strip()
    l = len(s) / c
    idx = 0
    arr = []
    for i in xrange(0, l):
        l = []
        for j in xrange(0, c):
            l.append(s[idx])
            idx += 1
        if i % 2 == 1:
            l.reverse()
        arr.append(l)
    ans = ""
    for i in xrange(0, c):
        for j in xrange(0, len(arr)):
            ans += arr[j][i]
    print ans

