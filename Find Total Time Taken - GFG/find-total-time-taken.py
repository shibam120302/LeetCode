from typing import List


class Solution:
    def totalTime(self, n : int, arr : List[int], time : List[int]) -> int:
        hm={}
        hm[arr[0]]=0
        cache=[0]*(n)
        for i in range(1,n):
            if arr[i] in hm:
                currentTime=cache[i-1]+1
                previousTime=cache[hm[arr[i]]]
                waitedTime=currentTime-previousTime
                if waitedTime<time[arr[i]-1]:
                    currentTime+=time[arr[i]-1]-waitedTime
                cache[i]=currentTime
                hm[arr[i]]=i
            else:
                hm[arr[i]]=i
                cache[i]=cache[i-1]+1
        return cache[n-1]



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
        
        
        arr=IntArray().Input(n)
        
        
        time=IntArray().Input(n)
        
        obj = Solution()
        res = obj.totalTime(n, arr, time)
        
        print(res)
        

# } Driver Code Ends