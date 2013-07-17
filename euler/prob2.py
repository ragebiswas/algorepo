# By considering the terms in the Fibonacci sequence whose values do not exceed four million, 
# find the sum of the even-valued terms

sum = 0
fib0 = 1
fib1 = 1

while(True):
    n = fib0 + fib1
    if(n > 4000000):
        break
    if(n % 2 == 0):
        sum += n
    fib0 = fib1
    fib1 = n
    print n
   
print sum

# 4613732

