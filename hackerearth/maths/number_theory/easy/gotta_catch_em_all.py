t,n = map(int,raw_input().split())
fct = [0]*(n+1)
fct1 = [0]*251
for i in range(1,n+1):
    for j in range(i,n+1,i):
        fct[j]+=1
    fct1[fct[i]]+=1
for i in range(1,251):
    fct1[i]+=fct1[i-1]
for i in range(0,t):
    k = int(raw_input())
    print fct1[fct[k]-1]