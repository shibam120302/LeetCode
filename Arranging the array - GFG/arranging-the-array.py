
from typing import List


class Solution:
    def reverse(self, arr, l, r):
        while l < r:
            arr[l], arr[r] = arr[r], arr[l]
            l += 1
            r -= 1

    def merge(self, arr, l, m, r):
        i = l  # Initial index of 1st subarray
        j = m + 1  # Initial index of IInd

        while i <= m and arr[i] < 0:
            i += 1

        # arr[i..m] is positive

        while j <= r and arr[j] < 0:
            j += 1

        # arr[j..r] is positive

        # reverse positive part of left sub-array (arr[i..m])
        self.reverse(arr, i, m)

        # reverse negative part of right sub-array (arr[m+1..j-1])
        self.reverse(arr, m + 1, j - 1)

        # reverse arr[i..j-1]
        self.reverse(arr, i, j - 1)

    def rearrangePosNeg(self, arr, l, r):
        if l < r:
            m = l + (r - l) // 2

            # Sort first and second halves
            self.rearrangePosNeg(arr, l, m)
            self.rearrangePosNeg(arr, m + 1, r)

            self.merge(arr, l, m, r)

    def Rearrange(self, n : int, arr : List[int]) -> None:
        self.rearrangePosNeg(arr, 0, len(arr) - 1)
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
        
        
        arr=IntArray().Input(2)
        
        obj = Solution()
        obj.Rearrange(n, arr)
        
        print(*arr, end=' ')
        print()

# } Driver Code Ends