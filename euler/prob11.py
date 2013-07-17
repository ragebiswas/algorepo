def up(n, i, j):
    return n[i][j] * n[i-1][j] * n[i-2][j] * n[i-3][j]
    
def down(n, i, j):
    return n[i][j] * n[i+1][j] * n[i+2][j] * n[i+3][j]
    
def left(n, i, j):
    return n[i][j] * n[i][j-1] * n[i][j-2] * n[i][j-3]
    
def right(n, i, j):
    return n[i][j] * n[i][j+1] * n[i][j+2] * n[i][j+3]

def diag1(n, i, j):
    return n[i][j] * n[i+1][j+1] * n[i+2][j+2] * n[i+3][j+3]

def diag2(n, i, j):
    return n[i][j] * n[i+1][j-1] * n[i+2][j-2] * n[i+3][j-3]

n = []
for line in open('prob11.in').readlines():
    e1 = [1, 1, 1, 1]
    n.append(e1 + [ int(i) for i in line.split()] + e1)

e2 = [1] * 28
n = [e2]*4 + n + [e2]*4



for r in n:
    for c in r:
        print '%02d' % (c),
    print
    
    

gm = 0
for i in range(4, 24):
    for j in range(4, 24):
        m = 1
        m = max(m, up(n,i,j))
        m = max(m, down(n,i,j))
        m = max(m, left(n,i,j))
        m = max(m, right(n,i,j))
        m = max(m, diag1(n,i,j))
        m = max(m, diag2(n,i,j))
        gm = max(gm, m)
        
print 'Answer:', gm