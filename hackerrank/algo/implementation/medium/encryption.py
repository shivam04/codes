#!/bin/python

import sys
import math

s = raw_input().strip()
low = int(math.floor(math.sqrt(len(s))))
up = int(math.ceil(math.sqrt(len(s))))
if low*low >= len(s):
    row=low
    col =low
elif low*up >= len(s):
    row=low
    col=up
elif up*up >=len(s):
    row = up
    col = up

m = 0
#print row,col
arr = list()

for i in range(0,col):
    m = i
    a = list()
    for j in range(0,row):
        if m < len(s):
            a.append(s[m])
        m = m + col
    arr.append(a)
for i in range(0,col):
    print "".join(e for e in arr[i]),
