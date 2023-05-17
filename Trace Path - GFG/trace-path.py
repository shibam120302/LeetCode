#User function Template for python3

class Solution:
    def isPossible(self, n: int, m: int, s: str) -> int:
        maxl, maxr, maxu, maxd, c1, c2 = 0, 0, 0, 0, 0, 0
        for i in range(len(s)):
            if s[i] == 'L':
                c1 -= 1
            elif s[i] == 'R':
                c1 += 1
            elif s[i] == 'U':
                c2 += 1
            else:
                c2 -= 1
            if c1 >= 0:
                maxr = max(c1, maxr)
            else:
                maxl = min(c1, maxl)
            if c2 >= 0:
                maxu = max(c2, maxu)
            else:
                maxd = min(c2, maxd)
        if maxr + 1 - maxl <= m and maxu + 1 - maxd <= n:
            return 1
        return 0

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, m = [int(x) for x in input().split()]
        s = input()
        
        ob = Solution()
        print(ob.isPossible(n, m, s))
# } Driver Code Ends