from typing import List

neg = -10**11
class Solution:
    def bestNode(self, N : int, A : List[int], P : List[int]) -> int:
        # code here
        leafs = set([i for i in range(1, N+1)])
        
        ans = [neg for i in range(N+1)]
        for i in P:
            if i in leafs:
                leafs.remove(i)

        for i in leafs:
            pointer = i
            sumo = 0
            while pointer != -1:
                sumo = A[pointer-1] - sumo
                ans[pointer] = max(sumo, ans[pointer])
                pointer = P[pointer-1]

        return max(ans)



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
        
        
        P=IntArray().Input(N)
        
        obj = Solution()
        res = obj.bestNode(N, A, P)
        
        print(res)
        

# } Driver Code Ends