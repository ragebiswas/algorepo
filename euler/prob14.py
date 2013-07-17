from array import array

arr = array('I', 1000001 * [0])

def collatz(n):
    if(arr[n] != 0):
        return arr[n]
        
    save = n    
    c = 1
    
    while(True):        
        if(n == 1):
            arr[save] = c
            return arr[save]
        if(n % 2 == 0):
            n = n/2
        else:
            n = 3*n + 1
        c = c+1
        
        
if __name__ == "__main__":
    m = 1
    mn = 0
    for i in range(1,1000001):
        x = collatz(i)
        if(x > m):
            m = x
            mn = i
    print "Max sequences is for number ", mn, ", seq length: ", m