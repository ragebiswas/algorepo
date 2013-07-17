def fact(n):
    res = 1
    for i in range(1, n+1):
        res = res * i
    return res
        
f = str(fact(100L))
print "Fact: ", f
print "Sum: ", sum(int(l) for l in f)