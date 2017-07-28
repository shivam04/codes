t = int(raw_input())
while t>0:
    ma = dict()
    s = raw_input()
    for i in s:
        if ma.has_key(i):
            ma[i]+=1
        else:
            ma[i]=1
    f = 0
    #print ma
    for i in s:
        if ma[i]>1:
            f = 1
            break
    #f = 0
    if f == 1:
        print "Yes"
    else:
        print "No"
    t-=1