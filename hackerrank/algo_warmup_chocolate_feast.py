# Enter your code here. Read input from STDIN. Print output to STDOUT
T = int(raw_input())
for i in range (0,T):
    n, c, m = map(int, raw_input().split())    
    answer = 0
    # write code to compute answer
    answer = n/c
    w = answer
    while w >= m:
      answer += 1
      w -= m
      w += 1
    
    print answer