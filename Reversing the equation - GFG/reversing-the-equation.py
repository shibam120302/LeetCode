#User function Template for python3

class Solution:
    def reverseEqn(self, s):
        res = ""
        n = len(s)
        i = n - 1
        
        st = []
        
        # # Traversing the string in reverse
        while i >= 0:
            # We traversed the string in reverse and pushed the characters in the stack
            # This is basically equivalent to 2 reversals. Hence, we get the 
            # numbers/variables in their correct order.
            # For example, say we have 20
            # Stack becomes: 0 2 <- top
            # Now, pushing the number in our result, we'll have 20
            if s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/':
                while len(st) > 0:
                    res += st.pop()
                res += s[i]
            else:
                st.append(s[i])
            i -= 1
            
        # Appending the last number/variable if any
        while len(st) > 0:
            res += st.pop()
            
        return res

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input().strip()
        ob = Solution()
        ans = ob.reverseEqn(s)
        print(ans)
# } Driver Code Ends