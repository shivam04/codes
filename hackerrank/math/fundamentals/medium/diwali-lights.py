# Enter your code here. Read input from STDIN. Print output to STDOUT
def mod_pow(a,b):
    ans = 1
    while b >0:
        if b%2==1:
            ans = (ans*a)%100000
        a = (a*a)%100000
        b/=2
    return (ans-1)%100000
    
t = int(raw_input())
for i in range(0,t):
    n = int(raw_input())
    print mod_pow(2,n)