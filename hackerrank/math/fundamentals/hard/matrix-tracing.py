mod = 10**9 + 7

def getfactmod(b):
    val = 1
    for i in range(1,b):
        val =((val%mod)*((i+1)%mod))%mod
    return val

def getpowermod(a,b):
    if b==0:
        return 1
    if b == 1:
        return a
    temp = getpowermod(a,b/2)
    if b%2==0:
        return ((temp%mod)**2)%mod
    else:
        return (a*((temp%mod)**2))%mod

def inversemod(a):
    return getpowermod(a,mod-2)

t = int(raw_input())
for i in range(0,t):
    n, m = map(int, raw_input().strip().split(' '))
    numerator = 1
    denominator = 1
    for j in range(1,n+m-1):
        numerator = ((numerator%mod)*(j%mod))%mod
    for j in range(1,n):
        denominator = ((denominator%mod)*(j%mod))%mod
    for j in range(1,m):
        denominator = ((denominator%mod)*(j%mod))%mod
    answer = ((numerator%mod)*(inversemod(denominator)%mod))%mod
    print answer