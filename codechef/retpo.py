# Codechef July 2014: Reach the point
# Math
nc = int(raw_input())
for i in range(0, nc):
    x, y = map(int, raw_input().split())
    if x < 0:
        x = -1 * x
    if y < 0:
        y = -1 * y
    if (x + y) % 2 == 0:
        print 2 * max(x, y)
    else:
        p1 = 2 * max(x, y - 1) + 1
        p2 = 2 * max(x, y + 1) + 1
        print min(p1, p2)