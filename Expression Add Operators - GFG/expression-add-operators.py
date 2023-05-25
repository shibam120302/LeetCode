#User function Template for python3

class Solution:
    def addOperators(self, S, target):
        def dfs(l, r, expr, cur, last, res):
            if l == r:
                if cur == target:
                    res.append(expr)
                return
            for i in range(l + 1, r + 1):
                if i == l + 1 or (i > l + 1 and S[l] != "0"):
                    s, x = S[l:i], int(S[l:i])
                    if last == None:
                        dfs(i, r, s, x, x, res)
                    else:
                        dfs(i, r, expr+"+"+s, cur + x, x, res)
                        dfs(i, r, expr+"-"+s, cur - x, -x, res)
                        dfs(i, r, expr+"*"+s, cur-last+last*x, last*x, res)
        
        res = []
        dfs(0, len(S), '', 0, None, res)
        return res


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int(input ())
    for _ in range (t):
        S = input()
        target = int(input())
        ob = Solution()
        res = ob.addOperators(S, target)
        res.sort()
        for combination in res:
            print(combination, end = ' ')
        print()
# } Driver Code Ends