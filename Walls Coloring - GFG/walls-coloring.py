#User function Template for python3

inf = 10**18
class Solution():
    def minCost(self, colors, N):
        ans = colors[0][:]
        for i in range(1, n):
            tmp = ans[:]
            ans = [inf, inf, inf]
            for j in range(3):
                ans[j] = min(ans[j], tmp[(j+1)%3]+colors[i][j])
                ans[j] = min(ans[j], tmp[(j+2)%3]+colors[i][j])
        return min(ans)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ =="__main__":
    for _ in range(int(input())):
        n = int(input())
        colors = []
        for i in range(n):
            tmp = [int(i) for i in input().split()]
            colors.append(tmp)
        print(Solution().minCost(colors, n))
# } Driver Code Ends