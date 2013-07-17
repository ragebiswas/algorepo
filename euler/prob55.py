def ispal(s):
    ln = len(s)
    for i in range(0, ln/2):
        if s[i] != s[ln-i-1]:
            return False
    return True


def numiters(n):
    it = 1
    while it < 50:
        l = [c for c in str(n)]
        l.reverse()
        n = n + int(''.join(l))
        if(ispal(str(n))):
            return it
        it = it + 1
    return 0
    

c = 0
for i in range(1, 10000):
    if numiters(i) == 0:
        print 'More than 50 iters required for: ', i
        c = c + 1
print 'Number of Lychrel numbers: ', c