n,a,b = map(int,raw_input().split())
arr = map(int,raw_input().split())
A = list()
B = list()
tt = arr[:]
print len(tt)
for i in range(len(tt)):
	#print arr[i]
	if a-arr[i] in arr and arr[i]!=0 and arr[arr.index(a-arr[i])]!=0:
		A.append(arr[i])
		A.append(a-arr[i])
		arr[arr.index(a-arr[i])] = 0
		arr[i] = 0
	#print arr

print A,len(A)
arr = tt[:]
for i in range(len(tt)):
	if b-arr[i] in arr and arr[i]!=0 and arr[arr.index(b-arr[i])]!=0:
		B.append(arr[i])
		B.append(b-arr[i])
		arr[arr.index(b-arr[i])] = 0
		arr[i] = 0
print B,len(B)
arr = tt[:]

