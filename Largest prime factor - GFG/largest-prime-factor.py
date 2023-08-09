#User function Template for python3
class Solution:
    def largestPrimeFactor (self, N):
        
        num = 2;
        # loop till sqrt(N)
        while ((num * num) <=N):
            if (N % num == 0): # if num divides N evenly
                N = N//num # divide N by num
            else:
                num+=1 # increase num if it don't divide N
        return int(N);


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N = int(input())
       

        ob = Solution()
        print(ob.largestPrimeFactor(N))
# } Driver Code Ends