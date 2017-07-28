t = int(raw_input().strip())
for q in xrange(t):
    n,k = raw_input().strip().split(' ')
    n,k = [int(n),int(k)]
    l = [e for e in range(1,n+1)]
    p = list()
    if k==0:
        print " ".join(str(e) for e in l)
        continue
    elif n%2 != 0 or k > n/2 or n%k != 0:
        print '-1'
        continue
    elif (n/k)%2 != 0:
        print -1
    else:
        u=0
        f=0
        for i in range(0,n):
            if f==0:
                #print i+1,(i+k+1)
                p.append(i+k+1)
            else:
                #print i+1,(i-k+1)
                p.append(i-k+1)
            u+=1
            if u%k == 0:
                u=0
                if f==0:
                    f = 1
                else:
                    f=0
        print " ".join(str(e) for e in p)
 
    