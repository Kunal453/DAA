class item:
    def __init__(self,profit,weight):
        self.profit = profit
        self.weight = weight
def FK(W, arr):
    arr.sort(key = lambda x:(x.profit/x.weight),reverse= True)
    fianlvalue = 0.0
    for item in arr:
        if item.weight <= W:
            W -= item.weight
            fianlvalue += item.profit
        else:
            fianlvalue += item.profit*W / item.weight
            break
    return fianlvalue
if __name__ == "__main__":
    W = 50
    arr = [item(60,10),item(100,20)]
    max_val = FK(W,arr)
    print(max_val)
