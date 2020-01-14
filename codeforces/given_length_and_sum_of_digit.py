m,s = map(int,raw_input().split())
if m==1 and s<10:
	print s,s
elif m>1 and s==0 or m==1 and s>9:
	print -1,-1
else:
	num = ""
	for i in range(m):
		if s>8:
			num = num+"9"
			s-=9
		elif s<9:
			num = num + str(s)
			s = 0
	if s!=0:
		print "-1 -1"

	else:
		num1 = num[::-1]
		num1 = list(num1)
		if num1[0]=="0":
			for i in range(0,len(num1)):
				if num1[i]!='0':
					num1[i] = str(int(num1[i])-1)
					num1[0] = "1" 
					break
		print "".join(num1),num