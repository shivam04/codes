flag = [0]*(2**18+5)
tr = [0]*(2**18+5)
max_level = 0
def left_side(tr,n,cur_lev):
    global max_level
    if flag[n]==0 and max_level<cur_lev:
        flag[n] = 1
        print tr[n]
        max_level = cur_lev
    if tr[2*n+1]!=0:
        left_side(tr,2*n+1,cur_lev+1)
    if tr[2*n+2]!=0:
        left_side(tr,2*n+2,cur_lev+1)
def right_side(tr,n,cur_lev):
    global max_level
    #print max_level,cur_lev
    if flag[n]==0 and max_level<cur_lev:
        flag[n] = 1
        #print flag[0:n]
        print tr[n]
        max_level = cur_lev
    if tr[2*n+2]!=0:
        right_side(tr,2*n+2,cur_lev+1)
    if tr[2*n+1]!=0:
        right_side(tr,2*n+1,cur_lev+1)
t = int(raw_input())
for w in range(t):
    tr = [0]*(2**18+5)
    n = int(raw_input())
    ks = map(int,raw_input().split())
    tr[0:len(ks)] = ks
    max_level = 0
    flag = [0]*(2**18+5)
    right_side(tr,0,1)
    max_level = 0
    left_side(tr,0,1)
    print 