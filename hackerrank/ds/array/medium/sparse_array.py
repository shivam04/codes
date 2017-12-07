n = int(raw_input())
st = dict()
for i in range(n):
    s = raw_input()
    if st.has_key(s):
        st[s]+=1
    else:
        st[s] = 1
q = int(raw_input())
for j in range(q):
    s = raw_input()
    if st.has_key(s):
        print st[s]
    else:
        print 0