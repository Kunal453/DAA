#n_queen
def n_queen(n):
    col = set()
    pdiag = set()
    ndiag = set()
    res = []
    board = [["."]*n for i in range(n)]
    
    def backtrack(r):
        if  r == n:
            copy = [" ".join(row) for row in board]
            res.append(copy)
            return
        for c in range(n):
            if c in col or (r + c) in pdiag or (r - c) in ndiag:
                continue
            col.add(c)
            pdiag.add(r + c)
            ndiag.add(r - c)
            board[r][c] = "Q"
            backtrack(r + 1)
            col.remove(c)
            pdiag.remove(r + c)
            ndiag.remove(r - c)
            board[r][c] = "."
    backtrack(0)
    for sol in res:
        for row in sol:
            print(row)
        print()

if __name__ == "__main__":
    n_queen(4)
