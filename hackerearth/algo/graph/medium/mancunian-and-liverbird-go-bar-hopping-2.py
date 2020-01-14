maxn = 10**6+3
left_c = [[0 for x in range(0,2)] for y in range(0,maxn)]
right_c = [[0 for x in range(0,2)] for y in range(0,maxn)]
#print left_c
n = int(raw_input())
f = map(int,raw_input().split())
f.insert(0,0)
f.insert(len(f),0)
#print f
for i in range(1,n+1):
    #print f[i-1]
    if f[i-1]==1:
        left_c[i][1] = left_c[i-1][1]+1
        left_c[i][0] = 1
    else:
        left_c[i][0] = left_c[i-1][0] +1
        left_c[i][1] = 1
    #print i,left_c[i]
for i in range(n,0,-1):
    if f[i]==1:
        right_c[i][0] = right_c[i+1][0]+1
        right_c[i][1] = 1
    else:
        right_c[i][0] = 1
        right_c[i][1] = right_c[i+1][1]+1
    #print i,right_c[i]
q = int(raw_input())
tr = 0
#print left_c[0:n+2]
#print right_c[0:n+2]
for i in range(0,q):
    s = raw_input().split()
    #print s[0]
    if s[0]=='U':
        tr = 1 - tr
    else:
        k = int(s[1])
        print left_c[k][tr]+right_c[k][tr]-1
