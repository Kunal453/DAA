// Huff man coding
import heapq
class node:
    def __init__(self,freq,symbol,left=None, right=None):
        self.freq = freq
        self.symbol = symbol
        self.left = left
        self.right = right
   def __lt__(self, nxt): 
        return self.freq < nxt.freq 
    
    def printNoodes(node, val= ''):
        newval = val + str(node.huff)
        if(node.left):
            printNoodes(node.left, newval)
        if(node.right):
            printNoodes(node.right, newval)
        if (not node.left and not node.right):
            print(f"{node.symbol} -> {newval}")
    
    chars = ['a','b','c','d','e','f']
    freq = [5, 9, 12, 13, 16, 45]
    nodes = []
    
    for x in range(len(chars)):
        heapq.heappush(nodes, node(freq[x],chars[x]))
        
        while len(node) > 1;
        left= heapq.heapqpop(nodes)
        right = heapq.heapqpop(nodes)
        
        left.huff = 0
        right.huff = 1
        
        newNodes = (left.freq + right.freq, left.symbol + right.symbol, left, right)
        
        heapq.heappush(nodes, newNodes)
        
    printNoodes(node[0])
