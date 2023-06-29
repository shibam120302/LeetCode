#User function Template for python3


class Solution:
    def isHappy (self, N):
        if (N == 1 or N == 7): 
            return 1 
        sum = N
        x = N 
        # this loop executes till the sum of square of 
        # digits obtained is not a single digit number 
        while(sum > 9): 
            sum = 0 
            # this loop finds the sum of square of digits 
            while (x > 0): 
                d = x%10 
                sum += d*d;
                x//=10 
            if (sum == 1) :
                return 1
            x = sum
        if(sum == 7): 
            return 1 
        return 0
    
    # function to find next happy number 
    def nextHappy(self, N):
        x=N+1;
        res=x;
        # check for every name
        while(True):
            if self.isHappy(x):
                return x
            x+=1
            res=x
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3


if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N = int(input())

        ob = Solution()
        print(ob.nextHappy(N))
# } Driver Code Ends