# your code goes here
n = int(raw_input())
a = map(int,raw_input().split())
if n<=2:
	print 0
else:
	sum = a[0]
	for i in range(1,n):
		sum = sum + a[i]
	if sum%3!=0:
		print 0
	else:
		p = sum/3
		cnt = [0 for x in range(0,n)]
		kj=0
		for i in range(n-1,-1,-1):
			kj+=a[i]
			if kj==p:
				cnt[i]+=1
		kj = 0
		#print cnt
		for i in range(n-2,-1,-1):
			cnt[i]+=cnt[i+1]
		#print cnt
		kj = 0
		ans = 0
		for i in range(0,n-2):
			kj+=a[i]
			if kj==p:
				ans+=cnt[i+2]
		print ans