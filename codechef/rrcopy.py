nc = int(raw_input())
for i in range(0, nc):
    n = int(raw_input())
    ar = map(int, raw_input().split())
    print len(set(ar))

