def ispalindrome(i):
    s = str(i)
    i = 0
    j = len(s) - 1
    while(i<j):
        if(s[i] != s[j]):
            return False
        i = i+1
        j = j-1
    return True
        
    
    
ret = 0

for i in range(100, 1000):
    for j in range(100, 1000):
        if(ispalindrome(i*j)):
            if(i*j > ret):
                ret = i*j
         
print ret