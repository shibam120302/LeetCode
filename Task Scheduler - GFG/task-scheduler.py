#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

from collections import Counter
class Solution:
    def leastInterval(self, N, K, tasks):
        mp = Counter(tasks)
        count = max(mp.values())
        
        ans = (count - 1) * (K + 1)
        for key, val in mp.items():
            if val == count:
                ans += 1
        return max(len(tasks), ans)
        # Code here

#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input ())
    for _ in range (t):
        N, K = list(map(int, input().split()))
        tasks = input().split()
        ob = Solution()
        res = ob.leastInterval(N, K, tasks)
        print(res)
# } Driver Code Ends