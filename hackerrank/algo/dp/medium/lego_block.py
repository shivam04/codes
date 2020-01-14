MOD = 10**9+7
def power(a,b):
    ans = 1
    while b>0:
        if b%2==1:
            ans = (ans*a)%MOD
        a = (a*a)%MOD
        b/=2
    return ans%MOD
t = int(raw_input())
dp = [0 for x in range(0,1002)]
dp[0] = 1
dp[1] = 1
dp[2] = 2
dp[3] = 4
dp[4] = 8
#print dp
for i in range(5,1001):
    dp[i] = (dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4])%MOD
#print dp
ans = [0 for x in range(0,1001)]
ans[0]=ans[1]=1
tw = [0 for x in range(0,1001)]
while t>0:
    t-=1
    n,m = map(int,raw_input().split())
    #print n,m
    for i in range(0,m+1):
        tw[i] = power(dp[i],n)
    for i in range(2,m+1):
        sumr = 0
        for j in range(1,i):
            sumr = sumr + (ans[j]*tw[i-j])%MOD
            sumr%=MOD
        ans[i] = tw[i]-sumr
        ans[i]%=MOD
    while ans[m]<0:
        ans[m]+=MOD
    print ans[m]