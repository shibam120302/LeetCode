#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

from collections import Counter
class Solution:
    def isStraightHand(self, N, groupSize, hand):
        mp = Counter(hand)
        for key in mp:
            if mp[key] <= 0:
                continue
            for i in range(groupSize - 1, -1, -1):
                mp[key + i] -= mp[key]
                if mp[key + i] < 0:
                    return False
        return True
        # Code here

#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int(input ())
    for _ in range (t):
        N, groupSize = list(map(int, input().split()))
        hand = list(map(int, input().split()))
        ob = Solution()
        res = ob.isStraightHand(N, groupSize, hand);
        print(res)
# } Driver Code Ends