def joystick(a,b):
	if a==0 or b==0:
		return 0
	elif a==1 and b ==1:
		return 0
	elif a==2 and b ==2:
		return 1
	elif b==2 and a>2:
		return 1 + joystick(b+1,a-2)
	elif b==1:
		return 1 + joystick(b+1,a-2)
	else:
		return 1 + joystick(a+1,b-2)

a1,a2 = map(int,raw_input().strip().split())
if a1>a2:
	print joystick(a2,a1)
else:
	print joystick(a1,a2)