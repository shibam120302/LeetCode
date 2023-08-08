#User function Template for python3


from math import gcd
from collections import defaultdict

class Solution:
    def countFractions(self, n, numerator, denominator):
        fractionCount = defaultdict(int)
        ans = 0

        for i in range(n):
            x = numerator[i]
            y = denominator[i]
            gcd_val = gcd(x, y)
            x //= gcd_val
            y //= gcd_val
            want_x = y - x
            want_y = y

            if (want_x, want_y) in fractionCount:
                ans += fractionCount[(want_x, want_y)]

            fractionCount[(x, y)] += 1

        return ans

#{ 
 # Driver Code Starts

#Initial Template for Python 3

for _ in range(int(input())):
    n = int(input())
    numerator = list(map(int,input().split()))
    denominator = list(map(int,input().split()))
    ob = Solution()
    print(ob.countFractions(n,numerator,denominator))
# } Driver Code Ends