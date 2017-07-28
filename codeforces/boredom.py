n = int(raw_input())
a = map(int,raw_input().split())
l = [0]*100001
for e in a:
	l[e] = l[e] + 1

dp = [0]*100001
dp[1] = l[1]
for i in range(2,100001):
	dp[i] = max(dp[i-1],dp[i-2]+l[i]*i)

print dp[100000]
	