# Enter your code here. Read input from STDIN. Print output to STDOUT
vis = [[0 for x in range(10)] for y in range(2)]
#print vis
def recurse_path(x,y,p):
    if p[x][y]=='1':
        return 0
    vis[x][y]=1
    tot = 1
    if x+1<2 and vis[x+1][y]==0:
        tot += recurse_path(x+1,y,p)
    if y+1<n and vis[x][y+1]==0:
        tot += recurse_path(x,y+1,p)
    if x+1<2 and y-1>=0 and vis[x+1][y-1]==0:
        tot += recurse_path(x+1,y-1,p)
    if x-1>=0 and vis[x-1][y]==0:
        tot += recurse_path(x-1,y,p)
    if y-1>=0 and vis[x][y-1]==0:
        tot += recurse_path(x,y-1,p)
    if x-1>=0 and y+1< n and vis[x-1][y+1]==0:
        tot += recurse_path(x-1,y+1,p)
    return tot
t = int(raw_input())
while t>0:
    t-=1
    p = list()
    n = int(raw_input())
    first = raw_input()
    second = raw_input()
    p.append(first)
    p.append(second)
    flag = 0
    vis = [[0 for x in range(10)] for y in range(2)]
    for i in range(0,2):
        for j in range(0,n):
            if vis[i][j]==0:
                k = recurse_path(i,j,p)
                if(k%2!=0):
                    flag = 1
    if flag==1:
        print "NO"
    else:
        print "YES"
    
    