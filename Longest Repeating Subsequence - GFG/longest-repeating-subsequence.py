#User function Template for python3

class Solution:
    def LongestRepeatingSubsequence(self,str):
        dp =[[-1 for i in range(len(str)+1)] for j in range(len(str)+1)]
        return self.lrs(str, 0, 0, dp)


    def lrs(self, s1, i, j, dp):
    
        # return if we have reached the
        #end of either string
        if i >= len(s1) or j >= len(s1):
            return 0
    
        if dp[i][j] != -1:
            return dp[i][j]
        
        # while dp[i][j] is not computed earlier
        if dp[i][j] == -1:
        
            # if characters at index m and n matches
            # and index is different
            # Index should not match
            if s1[i] == s1[j] and i != j:
                dp[i][j] = 1+self.lrs(s1, i+1, j+1, dp)
            
            # else if characters at index m and n don't match
            else: 
                dp[i][j] = max(self.lrs(s1, i, j+1, dp),
                                    self.lrs(s1, i+1, j, dp))
        
        # return answer
        return dp[i][j]
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		str = input()
		ob = Solution()
		ans = ob.LongestRepeatingSubsequence(str)
		print(ans)

# } Driver Code Ends