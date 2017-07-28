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
for i in range(len(tt)):
	if arr[i]!=0:
		if b-arr[i] in arr and arr[arr.index(b-arr[i])] != 0:
			B.append(arr[i])
			B.append(b-arr[i])
			arr[arr.index(b-arr[i])] = -3
			arr[i] = -3
print B
print arr
res = True
for i in arr:
	if i!=0 and i!=-3:
		res = False
		break

if res==True:
	print "YES"
	for i in arr:
		if i==0:
			print 0,
		else:
			print 1,

else:
	print "NO"
