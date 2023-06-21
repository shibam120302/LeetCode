#User function Template for python3
class Solution:
    def sumOfNaturals(self, n):
        
        MOD = int(1e9) + 7
        Sum = ((n*(n+1))%MOD)//2   # Computing (n*(n+1))/2
        
        return Sum


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        n = int(input())
        
        ob = Solution()
        print(ob.sumOfNaturals(n))
# } Driver Code Ends