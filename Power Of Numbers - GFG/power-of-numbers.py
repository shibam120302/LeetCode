#User function Template for python3

class Solution:    
    def modfun(self,N,R):
        #Base case
        if N==0:
            return 0
        # power is zero means answer is 1
        if R==0:
            return 1 
        y=0
        # if R is even
        if R%2==0: 
            #finding r/2 power as power is even then storing answer in y and if power is even like 2^4 we can simply do (2^2)*(2^2)
            y=self.modfun(N,R/2) 
            y = (y * y) % 1000000007
        #If R is odd
        else:
                y = N % 1000000007 
                # reduce the power by 1 to make it even. The reducing power by one can be done if we take one n out. Like 2^3 can be written as 2*(2^2)
                y = (y * self.modfun(N, R - 1) % 1000000007) % 1000000007
                
     
        # finally return the answer (y+mod)%mod = (y%mod+mod%mod)%mod = (y%mod)%mod
        return ((y + 1000000007) % 1000000007)
    
    
    def power(self,N,R):
        return self.modfun(N,R)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math

def main():
    
    T=int(input())
    
    while(T>0):
        
        N=input()
        R=N[::-1]
        
        ob=Solution();
        ans=ob.power(int(N),int(R))
        print(ans)
        
        T-=1

if __name__=="__main__":
    main()
# } Driver Code Ends