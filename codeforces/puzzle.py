n,m = raw_input().split()
n = int(n)
m = int(m)
a = map(int,raw_input().split())
a = sorted(a, reverse=True)
#print a
min = 1000000000
for i in range(0,m-n+1):
	if  a[i] - a[n+i-1] < min:
		min = a[i] - a[n+i-1] 
print min
