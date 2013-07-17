for i in range (1, 1001):
    for j in range (1, 1001):
        k = 1000-(i+j)
        if(i*i+j*j == k*k):
            print i,',',j,',',k,',prod=',i*j*k