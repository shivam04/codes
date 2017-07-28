t = int(raw_input())
st = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ"
lt = dict()
k = 0
for i in st:
    lt[i]=k
    k+=1
for i in range(t):
    ls = raw_input().split(" ")
    count = 0
    for j in ls:
        for m in range(len(j)):
            count += lt[j[m]] + m 
    print count*len(ls)