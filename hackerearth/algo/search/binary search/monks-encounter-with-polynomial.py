t = int(raw_input())
for k in range(t):
    a,b,c,k = map(int,raw_input().split())
    l = 0
    r = 100000
    ans = 0
    while(l<=r):
        mid = (l+r)/2
        if a*mid**2 + b*mid + c == k:
            ans = mid
            break
        elif a*mid**2 + b*mid + c < k:
            l = mid+1
        else:
            ans = mid
            r= mid-1
    print ans