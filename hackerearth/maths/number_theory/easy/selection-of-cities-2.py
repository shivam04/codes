mod = 10**9+7
def m_pow(n,b):
	ans = 1
	while b>0:
		if b%2==1:
			ans = (ans*n)%mod
		b/=2
		n = (n*n)%mod
	return ans


t = int(raw_input())
for i in range(0,t):
	n = int(raw_input())
	ans = (m_pow(2,n)-1)%mod
	print ans