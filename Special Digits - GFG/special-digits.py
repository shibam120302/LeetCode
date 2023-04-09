def generateAll(a,b,c,d,n):
    nums = []
    for i in range(n*min(a,b), n*max(a,b)+1):
        j = i
        flg = True
        while j:
            mod = j%10
            if mod != c and mod != d:
                flg = False
                break 
            j //=10
        if flg:
            nums.append(i)
    return nums
            
maxi = 10**5+1
mod = 10**9+7
factorials = [i for i in range(maxi+1)]
factorials[0] = 1
for i in range(1, maxi+1):
    factorials[i]*=factorials[i-1]
    factorials[i]%=mod
    
class Solution:
    def bestNumbers(self, N : int, A : int, B : int, C : int, D : int) -> int:
        pos = generateAll(A,B,C,D,N)
        ans = 0
        num = factorials[N]
        for i in pos:
            for j in range(N+1):
                sumo1 = A*j
                sumo2 = B*(N-j)
                if sumo1 + sumo2 == i:
                    den = factorials[j]*factorials[N-j]
                    allPos = (num*pow(den, mod-2,mod))%mod
                    ans += allPos
                    ans%= mod
        return ans
        



#{ 
 # Driver Code Starts
if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        N = int(input())
        
        
        A = int(input())
        
        
        B = int(input())
        
        
        C = int(input())
        
        
        D = int(input())
        
        obj = Solution()
        res = obj.bestNumbers(N, A, B, C, D)
        
        print(res)
        

# } Driver Code Ends