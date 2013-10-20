#
# Problem: http://www.spoj.com/problems/PT07Y/
# Category: Simple graphs (DFS)
#
def dfs(i):
    if visited[i]:
        return
    visited[i] = 1
    for x in vertices[i]:
        dfs(x)

n, m = map(int, raw_input().split())
vertices = [ [i] for i in range(0, n+1) ]
tm = m
while tm:
    tm -= 1
    a, b = map(int, raw_input().split())
    vertices[a].append(b)
    vertices[b].append(a)
    
visited = [0] * (n+2)
components = 0
for i in range(1, n+1):    
    if not visited[i]:
        dfs(i)
        components += 1

if (components > 1) or (m != n - 1):
    print 'NO'
else:
    print 'YES'
