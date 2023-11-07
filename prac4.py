def KsK(capacity,profit,wt,n):
    k = [[ 0 for i in range(capacity + 1)] for x in range( n + 1)]
    print(capacity)
    for i in range(n + 1):
        for w in range(capacity + 1):
            if i == 0 or w == 0:
                k[i][w] = 0
            elif wt[i - 1] <= w:
                k[i][w] = max(profit[i-1]+k[i-1][w-wt[i-1]],k[i-1][w])
            else:
                k[i][w] = k[i - 1][w]
    return k[n][capacity]

capacity = 50
profit = [60,100,120]
wt = [10,20,30]
n=len(profit)
print(KsK(capacity, profit, wt, n))
