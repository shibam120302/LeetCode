#User function Template for python3

class Solution:
    def matchGame(self, N):
        
        # If not divisible by 5, then return the remainder
        # when divided by 5 else return -1
        if N%5:
            return N%5
        else:
            return -1

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        
        ob = Solution()
        print(ob.matchGame(N))
# } Driver Code Ends