from typing import List

class Solution:
    
    def findMaxSubsetSum(self, N: int, A: List[int]) -> int:
        
        dp = [[0]*2 for i in range(N+1)]
        dp[0][0], dp[0][1] = 0, 0
        
        for i in range(1, N+1):
            
            dp[i][0] = dp[i-1][1]
            dp[i][1] = max(dp[i-1][0]+A[i-1], dp[i-1][1]+A[i-1])
            
        return max(dp[N][0], dp[N][1])
#{ 
 # Driver Code Starts

class IntArray:
    def __init__(self) -> None:
        pass
    def Input(self,n):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        N = int(input())
        
        
        A=IntArray().Input(N)
        
        obj = Solution()
        res = obj.findMaxSubsetSum(N, A)
        
        print(res)
        

# } Driver Code Ends