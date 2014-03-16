#
# Problem: https://www.hackerrank.com/contests/mar14/challenges/manasa-loves-maths
# Category: Basic math, hashmaps
#
from collections import Counter

def test(n):
    if n % 8 == 0:
        return True
    return False

ncases = int(raw_input())
v = []
for i in range(100, 1000):
    if i % 8 == 0:
        v.append(i)
        
vcounters = []
for i in v:
    vcounters.append(Counter(str(i)))

for i in range(0, ncases):
    s = raw_input().strip()
    if len(s) == 1:
        if test(int(s)):
            print 'YES'
        else:
            print 'NO'
    elif len(s) == 2:
        x = int(s)
        y = int(s[1] + s[0])
        if (test(x) or test(y)):
            print 'YES'
        else: 
            print 'NO'
    else:
        # Main bomb logic
        scounter = Counter(s)        
        for vcounter in vcounters:
            valid = True
            for k in vcounter.keys():
                if vcounter[k] > scounter[k]:
                    valid = False
            if valid:
                print 'YES'
                break
        if not valid:
            print 'NO'
                    
            
