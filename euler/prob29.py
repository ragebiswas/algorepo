l = []

for i in range(2, 101):
    for j in range(2, 101):
        x = i**j
        if x not in l:
            l.append(x)
            

print len(l)