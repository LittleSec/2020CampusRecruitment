def CountMin(n, a):
    def dfs(woods):
        if not woods or sum(woods) == 0:
            return 0
        
        res = min(woods)
        if len(woods) <= res:
            return len(woods)

        woods = [wood - res for wood in woods]

        start = 0
        for idx in range(len(woods)):
            if woods[idx] == 0:
                start = idx
                break

        mid = start
        for idx in range(start, len(woods)):
            if woods[idx] == 0:
                mid = idx

        l, r = woods[:mid], woods[mid:]
        res += dfs(l) + dfs(r)
        return res
    return dfs(a)

N = int(input())
arr = list(map(int, input().split(" ")))
print(CountMin(N, arr))
