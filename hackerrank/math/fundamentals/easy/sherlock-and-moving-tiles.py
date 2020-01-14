import math
l,s1,s2 = map(int,raw_input().split())
q = int(raw_input())
for i in range (0,q):
    n = int(raw_input())
    d = math.sqrt(2*n)
    k = l*math.sqrt(2)
    m = math.fabs(s1-s2)
    ans = (k-d)/m
    print ("%.4f"%ans)