# Problem: http://www.codechef.com/MAY14/problems/OJUMPS/
# Category: Simple coding
import os
n = int(raw_input())
if n >= 0:
	if n == 0 or (n - 1) % 6 == 0 or n % 6 == 0 or (n - 3) % 6 == 0:
		print 'yes'
	else:
		print 'no'
else:
	print 'no' 