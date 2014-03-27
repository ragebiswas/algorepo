# Enter your code here. Read input from STDIN. Print output to STDOUT
def insertion_sort(l):
    s = 0
    for i in xrange(1, len(l)):
        j = i-1 
        key = l[i]
        while (l[j] > key) and (j >= 0):
           l[j+1] = l[j]
           s += 1
           j -= 1
        l[j+1] = key
    return s
  


m = input()
ar = [int(i) for i in raw_input().strip().split()]
print insertion_sort(ar)