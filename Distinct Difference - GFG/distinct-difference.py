from typing import List

class Solution:
    def getDistinctDifference(self, N : int, A : List[int]) -> List[int]:
        left = [0 for i in range(N)]
        se = set()
        for i in range(1,N):
            se.add(A[i-1])
            left[i] = len(se)
        diff = [0 for i in range(N)]
        se = set()
        for i in range(N-2,-1,-1):
            se.add(A[i+1])
            diff[i] = left[i]-len(se)
        diff[-1] = left[-1]
        return diff
        



#{ 
 # Driver Code Starts
# class IntArray:

#     def __init__(self) -> None:
#         pass
    
if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        N = int(input())
        
        A=[int(i) for i in input().split()]
        
        obj = Solution()
        res = obj.getDistinctDifference(N, A)
        
        print(*res)
        

# } Driver Code Ends