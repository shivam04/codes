t = int(raw_input())
for i in range(0,t):
	n,c = map(int,raw_input().split())
	arr = map(int,raw_input().split())
	arr = sorted(arr)
	count = 0
	for j in range(n):
		if arr[j]<c:
			c-=arr[j]
			count+=1
	print count
