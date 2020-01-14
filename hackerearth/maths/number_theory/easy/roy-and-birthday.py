mod = 10**9+7
fact = [0]*1000100
inv = [0]*1000100
def ipow(a,n):
    ret = 1
    b = a
    while n>0:
        if n%2==1:
            ret = (ret*b)%mod
        b = (b*b)%mod
        n/=2
    return ret
def precalc():
    fact[0]=1
    fact[1]=1
    inv[0]=0
    inv[1]=1
    for i in range(2,1000100):
        fact[i] = (i*fact[i-1])%mod
        inv[i] = ipow(fact[i],mod-2)
def comb(n,r):
    if n<=0 or r<0 or n<r:
        return 0
    p = ((fact[n]*inv[r])%mod*(inv[n-r]))%mod
    return p
precalc()
t = int(raw_input())
vowels = ['a','e','i','o','u']
for i in range(0,t):
	v = 0
	c = 0
	st = raw_input()
	st1 = list(st)
	ar = dict()
	arr = [0]*26
	for j in range(0,len(st1)):
		if st1[j] in vowels:
			v+=1
			if ar.has_key(st1[j]):
			    ar[st1[j]]+=1
			else:
			    ar[st[j]]=0
		else:
			arr[ord(st[j])-97]+=1
			c+=1
	ans = comb(c+1,v)
	if c+1<v:
	    print "-1"
	else:
		q = fact[v]
		for i in vowels:
			q = (q*inv[ar[i]])%mod
		q = (q*fact[c])%mod
		for i in range(0,26):
			q = (q*inv[arr[i]])%mod
		ans = (ans*q)%mod
		print ans
