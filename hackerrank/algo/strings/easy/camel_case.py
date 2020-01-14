#!/bin/python

import sys


s = raw_input().strip()
count = 1
for ch in s:
    if ord(ch)>=65 and ord(ch)<=90:
        count+=1
print count
