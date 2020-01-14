import math
n = int(raw_input())
a = map(int, raw_input().split())
k = list()
ss = sum(a)
#print ss
fact = list()
end = math.sqrt(sum(a))
end = int(end)
#print end
for i in range(1,end):
    if(ss%i==0):
        fact.append(i)
        fact.append(ss/i)
if ss % end ==0:
    q = ss / end;
    if end == q:
        fact.append(end)
    else:
        fact.append(end)
        fact.append(q)
#print fact
for x in fact:
    i = 0
    p = x
    while True and i<n:
        x = x - a[i]
        f = 0
        if x==0:
            #print i
            x = p
        elif x<0:
            f = 1
            break
        i+=1
    #print "p:"+str(p)
    if x>0 and x<p and i==n:
        f = 1
    if(f==0):
        #print p
        k.append(p)
k = sorted(k)
print " ".join([str(e) for e in k])