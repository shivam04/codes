n = int(raw_input())
a = map(int,raw_input().split())
ans = -1
k = 1
for i in range(1,n):
	if a[i]>=a[i-1]:
		k+=1
	else:
		ans = max(ans,k)
		k=1
ans = max(ans,k)
print ans