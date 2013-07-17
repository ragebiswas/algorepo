def solve(numlines):  
  for i in range(0, len(numlines)-1):
    thisline = numlines[i]
    nextline = numlines[i+1]
    for j in range(0, len(thisline)-1):
      nextline[j] = max(thisline[j], thisline[j+1]) + nextline[j]
    #print nextline
  print numlines[-1][0]


nc = int(raw_input())

for c in range(0, nc):
  nl = int(raw_input())
  lines = []
  for l in range(0, nl):
    lines.append(raw_input())
   
  lines.reverse()
  numlines = []
  
  for line in lines:
    numline = [ int(x) for x in line.split() ] 
    numlines.append(numline)
  solve(numlines)
  

  

