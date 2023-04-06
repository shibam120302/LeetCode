# User functiovn Template for python3

class Solution:
    
    #Function to find equilibrium point in the array.
    def equalSum(self,A, N):
    
        #We store the sum of all array elements.
        sum = 0
        for i in range(0, N):
            sum += A[i]
    
        #sum2 is used to store prefix sum.
        sum2 = 0
    
        for i in range(0, N, +1):
            
            #Leaving out the value of current element from suffix sum.
            sum -= A[i]
            
            #Checking if suffix and prefix sums are same.
            if sum2 == sum:
                #returning the index or equilibrium point.
                return (i + 1)
            
            #Adding the value of current element to prefix sum.   
            sum2 += A[i]
            
        return -1


#{ 
 # Driver Code Starts
# Initial Template for Python 3

import math


def main():

    T = int(input())

    while(T > 0):

        N = int(input())

        A = [int(x) for x in input().strip().split()]
        ob=Solution()

        print(ob.equalSum(A, N))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends