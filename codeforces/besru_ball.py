n = int(raw_input())
a = map(int,raw_input().split())
m = int(raw_input())
b = map(int,raw_input().split())
a = sorted(a)
b = sorted(b)
count = 0
for i in range(len(a)):
	for j in range(len(b)):
		if abs(a[i]-b[j])<=1:
			count+=1
			b[j] = 1000
			break
print count
