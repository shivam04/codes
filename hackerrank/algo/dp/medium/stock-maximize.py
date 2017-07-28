# Enter your code here. Read input from STDIN. Print output to STDOUT
def getMaximumProfit(price):
    profit = 0
    maxSofar = 0
    for i in range(len(price)-1,-1,-1):
        if price[i]>=maxSofar:
            maxSofar = price[i]
        profit+=maxSofar-price[i]
    return profit
t = int(raw_input())
while t > 0:
    t-=1
    n = int(raw_input())
    price = map(int,raw_input().split())
    print getMaximumProfit(price)