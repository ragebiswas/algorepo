#
# Problem: http://www.spoj.com/problems/ACPC10A/
# Category: Simple coding
#
while True:
    s = str(raw_input())
    a, b, c = map(int, s.split())
    if a == 0 and b == 0 and c == 0:
        break
    if c - b == b - a:
        print "AP", c + (b-a)
    else:
        print "GP", c * int(b/a)
