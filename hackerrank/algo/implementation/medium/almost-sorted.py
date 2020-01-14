n = int(raw_input())
a = map(int,raw_input().split())
t = list()
f=0
for i in range(1,n):
    if a[i]<a[i-1]:
        if len(t)<2 or i-1-t[len(t)-1]==1:
            t.append(i-1)
        else:
            f=1
            print "no"
            break
if f==0:
    o = 0
    if len(t)==0:
        o = 1
        print "yes"
    if o==0:
        s = len(t)
        if s<=2:
            meth = "swap"
        else:
            meth = "reverse"
        l = t[0]
        r = t[len(t)-1]+1
        if (l==0 or a[r]>=a[l-1]) and (r==n-1 or a[l]<=a[r+1]):
            print "yes"
            print meth,l+1,r+1
        else:
            print "no"