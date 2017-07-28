def next_permutation(a):
    i = len(a)-1
    while i>0 and a[i-1]>=a[i]:
        i-=1
    if i<=0:
        return 'no answer'
    j = len(a)-1
    while a[j]<=a[i-1]:
        j-=1
    temp = a[i-1]
    a[i-1] = a[j]
    a[j] = temp
    j = len(a)-1
    while i < j:
        temp = a[i]
        a[i] = a[j]
        a[j] = temp
        i+=1
        j-=1
    return a
t = int(raw_input())
for i in range(0,t):
    a = raw_input()
    print ('').join(next_permutation(list(a)))