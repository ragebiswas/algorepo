def getscore(s):
    score = 0
    for c in s:
        score = score + (ord(c) - ord('A') + 1)
    return score




names = open('names.txt').read()
nl = [ i[1:-1] for i in names.split(',') ]
nl.sort()
sum = 0
p = 1
for n in nl:
    score = getscore(n)
    #print n, "->", p, "x", score
    sum = sum + (p * score)
    p = p+1

print "Final score: ", sum