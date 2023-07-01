#User function Template for python3

class Solution:
    def setBits(self, N):
        cnt = 0 
        while N>0:
            if (N & 1) :
                cnt+=1
            N>>=1
        return cnt


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		N = int(input())
		ob = Solution()
		ans = ob.setBits(N)
		print(ans)




# } Driver Code Ends