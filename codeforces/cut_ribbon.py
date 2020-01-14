p = map(int,raw_input().split())
n = int(p[0])
a = p[1:len(p)]
dp = [0]*4002
#print dp
a = sorted(a)
for i in range(0,n+1):
	dp[i] = -99999
dp[0] = 0
dp[a[0]] = 1
dp[a[1]] = 1
dp[a[2]] = 1
for i in range(0,n+1):
	for j in range(len(a)):
		if a[j] > i:
			break
		dp[i] = max(dp[i],1+dp[i-a[j]])

print dp[n]