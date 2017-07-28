import sys
from collections import defaultdict
m = defaultdict()
def fun(i,j,cnt,p,q):
    if i<1 or i>8 or j<1 or j>8:
        return sys.maxsize
    if i==p and j==q:
        #ans = min(ans,cnt)
        return cnt
    if m.has_key((i,j)):
        if m[(i,j)]<cnt:
            return sys.maxsize
        else:
            m[(i,j)] = cnt
    else:
        m[(i,j)] = cnt
    return min(min(min(fun(i+1,j+2,cnt+1,p,q),
    fun(i-2,j-1,cnt+1,p,q)),
    min(fun(i-1,j+2,cnt+1,p,q),
    fun(i+1,j-2,cnt+1,p,q))),
    min(min(fun(i-1,j-2,cnt+1,p,q),
    fun(i+2,j+1,cnt+1,p,q)),
    min(fun(i+2,j-1,cnt+1,p,q),
    fun(i-2,j+1,cnt+1,p,q))))
ans = sys.maxsize
x1,y1,x2,y2 = map(int,raw_input().split())
m[(x1,y1)] = 0
print fun(x1,y1,0,x2,y2)
