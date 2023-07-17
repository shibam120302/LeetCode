#User function Template for python3

class Solution:
    def FirstNonRepeating(self, A):
        n = len(A)
        f = [0] * 26
        last = [-1] * 26
        
        for i in range(n):
            if last[ord(A[i]) - ord('a')] == -1:
                last[ord(A[i]) - ord('a')] = i
        
        ans = ""
        for i in range(n):
            f[ord(A[i]) - ord('a')] += 1
            ch = '#'
            x = n + 1
            for j in range(26):
                if f[j] == 1 and x > last[j]:
                    ch = chr(j + ord('a'))
                    x = last[j]
            
            ans += ch
        
        return ans

#{ 
 # Driver Code Starts

#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		A = input()
		ob = Solution()
		ans = ob.FirstNonRepeating(A)
		print(ans)

# } Driver Code Ends