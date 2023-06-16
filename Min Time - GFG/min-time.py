from collections import defaultdict
class Solution:
    def minTime(self,n,locations,types):
        dict=defaultdict(list)
        var=set()
        for a,b in zip(locations,types):
            dict[b].append(a)
            var.add(b)
        var.add(10**10)
        dict[10**10]=[0]
        var=list(sorted(var))
        dp=[[0]*2 for _ in range(len(var)+1)]
        for el in dict.keys():
            dict[el].sort()
        p_left,p_right=0,0
        for i,c in enumerate(var):

            left,right=dict[c][0],dict[c][-1]
            dp[i+1][0]=abs(right-left)+min(dp[i][0]+abs(right-p_left),dp[i][1]+abs(p_right-right))
            dp[i+1][1]=abs(right-left)+min(dp[i][0]+abs(left-p_left),dp[i][1]+abs(left-p_right))
            p_left,p_right=left,right
        return(min(dp[-1])) 

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
        
        n = int(input())
        
        
        locations=IntArray().Input(n)
        
        
        types=IntArray().Input(n)
        
        obj = Solution()
        res = obj.minTime(n, locations, types)
        
        print(res)
        

# } Driver Code Ends