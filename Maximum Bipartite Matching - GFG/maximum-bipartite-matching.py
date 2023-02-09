#User function Template for python3


class Solution:
    def try_kunh(self, u, G, used, mt):
        for v in range(len(G[0])):
            if(G[u][v] and used[v] == False):
                used[v] = True
                if(mt[v] < 0 or self.try_kunh(mt[v], G, used, mt)):
                    mt[v] = u
                    return True
        return False
    def maximumMatch(self, G):
        m = len(G)
        n = len(G[0])
        N = max(n,m)
        ans = 0
        mt = [-1 for i in range(N)]
        for i in range(m):
            used = [False for j in range(N)]
            if(self.try_kunh(i, G, used, mt)):
                ans = ans+1
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		m, n = map(int, input().strip().split())
		G = []
		for i in range(m):
			G.append(list(map(int, input().strip().split())))
		obj = Solution()
		ans = obj.maximumMatch(G)
		print(ans)
# } Driver Code Ends