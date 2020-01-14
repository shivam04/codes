t = int(raw_input())
while t>0:
    t-=1
    ma = {'z':0, 'y':0, 'x':0, 'w':0, 'v':0, 'u':0, 't':0, 's':0,'r':0, 'q':0, 'p':0,'o':0, 'n':0,'m':0, 'l':0, 'k':0, 'j':0, 'i':0, 'h':0, 'g':0, 'f':0, 'e':0, 'd':0, 'c':0, 'b':0,'a':0}
    #print ma
    s = raw_input()
    for i in s:
        ma[i]+=1
    #print ma
    ma = sorted(ma.items(), key=lambda x: x[1])
    #print ma
    k = ma[0][1]
    ld = list(list())
    j = 0
    ld.append([])
    for i in range(0,len(ma)):
        if ma[i][1]==k:
            ld[j].append(ma[i][0])
        else:
            ld[j] = sorted(ld[j],reverse=True)
            ld.append([ma[i][0]])
            j+=1
            k = ma[i][1]
    for l in ld:
        for w in l:
            print w,
    print
    
    
