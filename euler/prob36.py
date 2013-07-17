# 1 mil = 0b11110100001001000000

minb = 0b1 # obi-wan
maxb = 0b1111111111

sum = 0 # for '1'

while minb <= maxb:
    l = str(bin(minb))[2:] 
    
    r1 = l[::-1]
    r2 = r1[1:]
    
    i1 = int(l+r1, 2)
    i2 = int(l+r2, 2)
    
    ls1 = str(i1)
    ls2 = str(i2)
    
    rs1 = ls1[::-1]
    rs2 = ls2[::-1]
    
    if (ls1 == rs1): 
        print ls1, "(Bin: ", l+r1, ")"
        sum += i1
    
    if(ls2 == rs2):
        print ls2, "(Bin: ", l+r2, ")"
        sum += i2
        
    minb = minb+1
    
print 'Answer:', sum
    

