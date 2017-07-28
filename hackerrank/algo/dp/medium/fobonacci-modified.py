p = list()
t1,t2,n = map(int,raw_input().split())
p.append(t1)
p.append(t2)
for i in range(2,n):
    r = p[i-2] + p[i-1]*p[i-1]
    p.append(r)
print p[n-1]