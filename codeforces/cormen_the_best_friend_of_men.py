m,k = map(int,raw_input().split())
a = map(int,raw_input().split())
i = 1
n = len(a)
c = 0
while i < n:
	if a[i]+a[i-1]>=k:
	#	print i , a[i]+a[i-1]
		i+=1
	else:
		p = k -a[i]
		q = k - a[i-1]
		w = k - (a[i]+a[i-1])
		if p < q and a[i-1]+a[i-2]<k and i>1:
			a[i-1]+=w
			c+=w
		else:
			a[i] +=w
			c+=w
		i+=1
print c
for i in range(n):
	print a[i],