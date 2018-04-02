#code
from __future__ import division
import math
tc = int(input())
while(tc!=0):
    n, m = map(int, input().split())
    #step 1 - calculate the log of m
    logval = math.log10(m)
    #step 2 - divide the log calculated by n
    temp = logval/n
    #step 3 - calculate the antilog
    root = pow(10, temp)
    #step 4 - round the antilog value
    ans = round(root)
    if(pow(ans, n) == m):
        print(ans)
    else:
        print(-1)
    tc -= 1 