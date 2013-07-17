f = open('prob18.in')
lines = f.readlines()
lines.reverse()

numlines = []

for line in lines:
  numline = [ int(x) for x in line.split() ] 
  numlines.append(numline)
  

for i in range(0, len(numlines)-1):
  thisline = numlines[i]
  nextline = numlines[i+1]
  for j in range(0, len(thisline)-1):
    nextline[j] = max(thisline[j], thisline[j+1]) + nextline[j]
  print nextline
  
  
print "Answer:", numlines[-1][0]
  

