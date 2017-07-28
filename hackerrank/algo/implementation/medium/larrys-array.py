t = int(raw_input())
for i in range(t):
    n = int(raw_input())
    a = map(int,raw_input().split())
    sume = 0
    c = 0
    for j in range(n):
        c=0
        for k in range(j+1,n):
            if a[j]>a[k]:
                c+=1
        sume+=c
    if sume%2==0:
        print "YES"
    else:
        print "NO"