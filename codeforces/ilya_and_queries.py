def lis(arr):
	n = len(arr)
	lis = [0]*n
	for i in range (1 , n):
		if arr[i] == arr[i-1]:
			lis[i] = lis[i-1]+1
		else:
			lis[i] = lis[i-1]
	return lis
arr = list(raw_input().strip())
m = int(raw_input())
lis = lis(arr)
while m > 0:
	m-=1
	l,r = map(int,raw_input().split())
	print lis[r-1]-lis[l-1]