fa = [1]*10
for i in range(1, 10):
    fa[i] = fa[i-1]*i
    fa[0] = 1
    
def test(n):
    s = [ fa[int(i)] for i in str(n) ]
    x = 0
    for i in s:
        x += i   
    return x == n
    


sum = 0

for i in range(3, 9999999):
    if test(i):
        sum += i
        print 'Found:', i

print 'Answer: ', sum       