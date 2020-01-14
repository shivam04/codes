t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    k = 0
    a.sort()
    p = []
    q = []
    for i in range(n):
        if a[i]%2==0:
            p.append(a[i])
        else:
            q.append(a[i])
    a = p+q
    for i in range(n):
        print(a[i],end=" ")
    print()