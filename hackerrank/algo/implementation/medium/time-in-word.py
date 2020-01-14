#!/bin/python

import sys


h = int(raw_input().strip())
m = int(raw_input().strip())
f = ["one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","twenty one","twenty two","twenty three","twenty four","twenty five","twenty six","twenty seven","twenty eight","twenty nine"]
if m==0:
    print f[h-1],"o' clock"
elif m==15:
    print "quarter past",f[h-1]
elif m==45:
    print "quarter to",f[h]
elif m == 30:
    print "half past",f[h-1]
elif m<30:
    print f[m-1],"minutes past",f[h-1]
elif m>30:
    print f[60-m-1],"minutes to",f[h]
    
    