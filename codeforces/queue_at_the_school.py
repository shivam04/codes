n,t = map(int,raw_input().split())
seq = raw_input()
seq_l = list(seq)
for j in range(0,t):
	i = 0
	while i < n-1:
		#print i,
		if seq_l[i]=='B' and seq_l[i+1]=='G':
			seq_l[i]='G'
			seq_l[i+1]='B'
			i+=1
			#print i
		i+=1
	#print seq_l
print "".join(seq_l) 