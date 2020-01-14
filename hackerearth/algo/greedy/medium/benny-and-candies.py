mod = 2**32
n,m = map(int,raw_input().split())
a,b = map(int,raw_input().split())
x = (0*a)%m+b
x%=mod
c = (x>>8)
lst = c
ans = 0
for i in range(2,n+1):
    x = (x%m*a)+b
    x%=mod
    c = (x>>8)
    now = c
    #x%=m
    if(lst<now):
        ans+=(1*(now-lst))
    lst = now
print ans
        

    

    