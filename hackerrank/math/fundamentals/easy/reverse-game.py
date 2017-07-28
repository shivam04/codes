t = input()
while t:
    n,k=map(int,raw_input().split())
    a = [0]*n
    j = n-1
    n-=1
    for i in range (0,n+1):
        if(i%2==0):
            a[i] = n
        else:
            a[i] = j-n
            n-=1
        #print j,n
    #print a
    print a.index(k)
    t-=1