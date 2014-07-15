# Codechef July 2014: Count substrings
# Easy math
nc = int(raw_input())
for i in range(0, nc):
    l = int(raw_input())
    counts = [0] * l
    str = raw_input()
    counts[0] = 1 if (str[0] == '1') else 0
    lastcount = counts[0]
    for j in range(1, l):       
        if str[j] == '1':
            counts[j] = lastcount + 1
            lastcount += 1
    ans = 0
    for j in range(0, l):
        if counts[j] != 0:
            ans += (lastcount - counts[j]) + 1
    print ans