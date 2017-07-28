n = int(raw_input())
a = map(int,raw_input().split())
maxs = -1
c_o=0
c_z=0
for i in range(0,n):
	if a[i]==1:
		c_o+=1
		if c_z>0:
			c_z-=1
	else:
		c_z+=1
		maxs = max(maxs,c_z)

print c_o+maxs