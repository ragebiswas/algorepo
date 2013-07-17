r = int(raw_input())

s1 = 0
s2 = 0
w = 0
l = 0

for i in xrange(0, r):
    str = raw_input().split()
    s1 += int(str[0])
    s2 += int(str[1])
    if s1 >= s2:
        if s1 - s2 > l:
            w = 1
            l = s1 - s2
    else:
        if s2 - s1 > l:
            w = 2
            l = s2 - s1

print w, l
