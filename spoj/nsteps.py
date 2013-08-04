#
# SPOJ: Number Steps
# Category: Simple Coding
#
num_cases = int(raw_input())
for i in xrange(0, num_cases):
    s = str(raw_input()).split()
    x = int(s[0])
    y = int(s[1])
    if x == y:
        if (x + y) % 4 == 0:
            print x + y
        else:
            print x + y - 1
    elif x - y == 2:
        if x % 2 == 0:
            print x + y
        else:
            print x + y - 1
    else:
        print 'No Number'
