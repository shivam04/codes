# your code goes here
n,m = map(int,raw_input().split())
a = map(int,raw_input().split())
p = [0]*100005
dp = [0]*n
for i in range(n-1,-1,-1):
	if i == n-1:
		dp[i] = 1
		p[a[i]] = 1
	else:
		if p[a[i]] == 0:
			dp[i] = dp[i+1] + 1
			p[a[i]] = 1
		else:
			dp[i] = dp[i+1]

while m > 0:
	m-=1
	l = int(raw_input())
	print dp[l-1]
