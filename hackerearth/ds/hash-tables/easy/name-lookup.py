n = int(raw_input())
lis = dict()
for i in range(0,n):
	m,st = raw_input().split()
	#print m,st
	lis[m] = st
#print lis
q = int(raw_input())
for i in range(q):
	m = raw_input()
	print lis[m]