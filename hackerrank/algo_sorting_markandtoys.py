# Enter your code here. Read input from STDIN. Print output to STDOUT
def max_toys(prices, rupees):
  #Compute and return final answer over here
  prices.sort()
  answer = 0
  tot = 0
  for p in prices:
    if tot + p > rupees:
      break
    else:
      answer += 1
      tot += p
  return answer

if __name__ == '__main__':
  n, k = map(int, raw_input().split())
  prices = map(int, raw_input().split())
  print max_toys(prices, k)