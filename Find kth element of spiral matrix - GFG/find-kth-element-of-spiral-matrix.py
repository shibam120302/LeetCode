#User function Template for python3


class Solution:
    def findK(self, a, n, m, k):
        top = 0
        left = 0
        right = m - 1
        bottom = n - 1
        direction = 0
        count = 0
       
        AA = []
        while top <= bottom and left <= right:
            if direction == 0:
                for i in range(left, right + 1):
                    AA.append(a[top][i])
                top += 1
                direction = 1
                
            if direction == 1:
                for i in range(top, bottom + 1):
                    AA.append(a[i][right])
                right -= 1
                direction = 2

            if direction == 2:
                for i in range(right, left - 1, -1):
                    AA.append(a[bottom][i])
                bottom -= 1
                direction = 3

            if direction == 3:
                for i in range(bottom, top - 1, -1):
                    AA.append(a[i][left])
                left += 1
                direction = 0
            
        return AA[k-1]
#{ 
 # Driver Code Starts

#Initial Template for Python 3

for _ in range(int(input())):
    n, m, k = map(int,input().split())
    a = [
            list(map(int,input().split()))
            for _ in range(n)
        ]
    
    ob = Solution()
    print(ob.findK(a,n,m,k))
    
# } Driver Code Ends