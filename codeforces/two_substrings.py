s = list(raw_input())
ns = s[:]
f1 = 0 
f2 = 0
for i in range(len(s)-1):
	if s[i]=='A' and s[i+1]=='B':
		f1 = 1
		s[i] = s[i+1] = '*'
		break
for i in range(len(s)-1):
	if s[i]=='B' and s[i+1]=='A':
		f2 = 1
		break
#print 1,f1,f2,ns,s
if f1==1 and f2==1:
	print "YES"
else:
	s = ns
	f1 = 0
	f2 = 0
	for i in range(len(s)-1):
		if s[i]=='B' and s[i+1]=='A':
			f1 = 1
			s[i] = s[i+1] = '*'
			break
	for i in range(len(s)-1):
		if s[i]=='A' and s[i+1]=='B':
			f2 = 1
			break
	#print 2,f1,f2
	if f1==1 and f2==1:
		print 'YES'
	else:
		print 'NO'