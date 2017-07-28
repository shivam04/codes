def fact(n):
    f = 1
    for i in range (1,n+1):
        f = (f*i)%1000000007
    return f
def mod_pow(n,p,m):
    ans = 1
    x=n
    while(p>0):
        if(p%2==1):
            ans = (ans*x)%m
        x=(x*x)%m
        p=p/2
    return ans
t = input()
for i in range (0,t):
    n,m = map(int,raw_input().split())
    nr = fact(n+m-1)%1000000007
    temp = ((fact(n)%1000000007)*(fact(m-1)%1000000007))%1000000007
    dr = mod_pow(temp,1000000005,1000000007)%1000000007
    ans = (nr*dr)%1000000007
    print (ans)