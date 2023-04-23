class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        n = len(s)
        mod = 10**9 + 7
        dp = [0] * (n+1)
        dp[n] = 1
        
        for i in range(n-1, -1, -1):
            if s[i] == '0':
                continue
            num = 0
            for j in range(i, n):
                num = num*10 + int(s[j])
                if num > k:
                    break
                dp[i] = (dp[i] + dp[j+1]) % mod
        
        return dp[0]
