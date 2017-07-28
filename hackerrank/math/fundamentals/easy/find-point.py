t =  int(raw_input())
for i in range(t):
    (x1,y1,x2,y2) = map(int,raw_input().split())
    x = 2*x2 - x1 
    y = 2*y2 - y1
    print '{0} {1}'.format(x, y)