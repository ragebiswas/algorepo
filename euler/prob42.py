# Project Euler Problem 42

words = [ w[1:-1] for w in open('words.txt').read().split(",") ]

# Max word length is 14, each can be 'Z', so max can be 14 * 26

maxlength = max([ len(w) for w in words ])
maxtrianglenum = maxlength * 26

tnums = []
tnum = 1
n = 1

while tnum <= maxtrianglenum:
  tnums.append(tnum)
  n += 1
  tnum = (n * (n+1)) / 2
  
  
tw = 0  
for w in words:
  sum = 0
  for c in w:
    sum += (ord(c) - ord('A') + 1)
  if sum in tnums:
    tw += 1
    print w, ' is a triangle word'
    
print 'Total: ', tw
