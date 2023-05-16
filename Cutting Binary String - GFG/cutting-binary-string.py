#User function Template for python3

class Solution:
    @staticmethod
    def cuts(s: str) -> int:
        c = list(s)
        l = len(c)
        dp = [0] * (l+1)
        dp[0] = 0
        for i in range(1, l+1):
            index = i-1
            if c[index] == '0':
                dp[i] = -1
            else:
                dp[i] = -1
                t = 1000
                count = 0
                for j in range(i):
                    if c[index-j] == '1':
                        count += Solution.num(j)
                        if Solution.check(count) and dp[index-j] != -1:
                            w = 1 + dp[index-j]
                            t = min(w, t)
                if t != 1000:
                    dp[i] = t
        return dp[l]
    
    @staticmethod
    def num(y):
        if y == 0:
            return 1
        x = 2
        for i in range(1, y):
            x = x << 1
        return x
    
    @staticmethod
    def check(n):
        if n == 0:
            return False
        if n == 1:
            return True
        if n % 5 != 0:
            return False
        else:
            return Solution.check(n//5)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        s = input()

        solObj = Solution()

        print(solObj.cuts(s))

# } Driver Code Ends