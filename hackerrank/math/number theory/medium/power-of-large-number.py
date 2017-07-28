# Enter your code here. Read input from STDIN. Print output to STDOUT
def power(a,b,mod):
    ans = 1
    while b>0:
        if b%2==1:
            ans = (ans*a)%mod
        a = (a*a)%mod
        b/=2
    return ans
t = int(raw_input())
while t>0:
    t-=1
    a,b = raw_input().strip().split()
    A = 0
    mod = 10**9+7
    B = 0
    for i in range(len(a)):
        A = (A*10 + int(a[i]))%mod
    p = mod-1
    for i in range(len(b)):
        B = (B*10 + int(b[i]))%p
    if B == 0:
        print 1
    else:
        print power(A,B,mod)