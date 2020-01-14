def gcd(l,b):
    if(b==0):
        return l
    return gcd(b,l%b)
t= input()
for i in range (0,t):
    l,b = map(int,raw_input().split())
    sq = gcd(l,b);
    print ((l*b)/(sq*sq))