#
# Problem: http://www.spoj.com/problems/ABSYS/
# Category: Simple coding
#
nc = int(raw_input())
w = 'machula'
while nc != 0:
  s = str(raw_input())
  if s.strip() == '' or len(s.split()) != 5:
    continue
  nc -= 1
  toks = s.strip().split()
  if w in toks[0]:
    m = int(toks[4])-int(toks[2]) 
    print str(m) + " + " + toks[2] + " = " + toks[4] 
  elif w in toks[2]:
    m = int(toks[4])-int(toks[0]) 
    print toks[0] + " + " + str(m) + " = " + toks[4]
  elif w in toks[4]:
    m = int(toks[0])+int(toks[2])
    print toks[0] + " + " + toks[2] + " = " + str(m) 
  else:
    print s

