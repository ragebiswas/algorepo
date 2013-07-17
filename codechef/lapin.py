def build_map(s):
    m = {}
    for c in s:
        if c not in m:
            m[c] = 0
        m[c] += 1
    return m

nc = int(raw_input())
for i in range(0, nc):
    s = raw_input().strip()
    left = s[ : len(s) / 2 ]
    right = s[ len(s) / 2 : ]
    if len(left) != len(right):
        right = right[1:]
    if build_map(left) == build_map(right):
        print 'YES'
    else:
        print 'NO'