def lcs(n,m,s1,s2):
    l = [[0 for x in xrange(m+1)] for x in xrange(n+1)]
    for i in range(0,n+1):
        for j in range(0,m+1):
            if i==0 or j == 0:
                l[i][j]=0
            elif s1[i-1]==s2[j-1]:
                l[i][j] = 1 + l[i-1][j-1]
            else:
                l[i][j] = max(l[i-1][j], l[i][j-1])
    index = l[n][m]
    lcs = [""] * (index)
    
    i = n
    j = m
    #print s1,s2
    while i > 0 and j > 0:
        if s1[i-1] == s2[j-1]:
            lcs[index-1] = s1[i-1]
            i-=1
            j-=1
            index-=1
        elif l[i-1][j] > l[i][j-1]:
            i-=1
        else:
            j-=1
 
    print " ".join(str(e) for e in lcs)
                
n,m = map(int,raw_input().split())
s1 = map(int,raw_input().split())
s2 = map(int,raw_input().split())
lcs(n,m,s1,s2)