t = int(raw_input())
for i in range(0,t):
	n = int(raw_input())
	m = 5*n*n+4
	h = 5*n*n-4
	b = int((5*n*n+4)**(0.5))
	c = int((5*n*n-4)**(0.5))
	#print (b , c)
	if b*b == m or c*c==h:
		print("IsFibo")
	else:
		print("IsNotFibo")