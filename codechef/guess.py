# Codechef June 2014 (easy math)
nc = int(raw_input())
for tc in range(0, nc):
	N, M = map(long, raw_input().split())
	if N == 1 and M == 1:
		print "0/1"
	elif (N % 2 == 1) and (M % 2 == 1):
		print str(int(N*M/2)) + "/" + str(N*M)
	else:
		print "1/2"

