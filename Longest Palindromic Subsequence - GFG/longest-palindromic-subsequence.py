#User function Template for python3

class Solution:
    def longestPalinSubseq(self, A):
        n = len(A)
        B = A
        B = B[::-1]
        
        dp = []
        for i in range(n+1):
            l = [0]*(n+1)
            dp.append(l)
        
        for i in range(n+1):
            for j in range(n+1):
                if i==0 or j==0:
                    dp[i][j] = 0
                else:
                    if A[i-1] == B[j-1]:
                        dp[i][j] = 1+dp[i-1][j-1]
                    else:
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        
        return dp[n][n]
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input()
        ob = Solution()
        ans = ob.longestPalinSubseq(s)
        print(ans)
# } Driver Code Ends