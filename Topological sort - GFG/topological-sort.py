
class Solution:
    
    # A recursive function used by topologicalSort
    def DFSUtil(self,adj,v,visited,stack):

        #marking the current vertex as visited.
        visited[v] = True

        #traversing over the adjacent vertices.
        for i in adj[v]:
            
            #if any vertex is not visited, we call the function recursively.
            if visited[i] == False:
                self.DFSUtil(adj,i,visited,stack)

        #pushing the current vertex into the stack.
        stack.insert(0,v)
    
    #Function to return list containing vertices in Topological order.
    def topoSort(self, V, adj):
        
        #using boolean array to mark visited nodes and currently 
        #marking all the nodes as false.
        visited = [False]*V
        stack =[]

        #traversing over all the vertices.
        for i in range(V):
            
            #if the current vertex is not visited, we call the topo function.
            if visited[i] == False:
                self.DFSUtil(adj,i,visited,stack)

        #returning the stack.
        return stack

#{ 
 # Driver Code Starts
# Driver Program

import sys
sys.setrecursionlimit(10**6)
        
def check(graph, N, res):
    if N!=len(res):
        return False
    map=[0]*N
    for i in range(N):
        map[res[i]]=i
    for i in range(N):
        for v in graph[i]:
            if map[i] > map[v]:
                return False
    return True

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        e,N = list(map(int, input().strip().split()))
        adj = [[] for i in range(N)]
        
        for i in range(e):
            u,v=map(int,input().split())
            adj[u].append(v)
            
        ob = Solution()
        
        res = ob.topoSort(N, adj)
        
        if check(adj, N, res):
            print(1)
        else:
            print(0)
# Contributed By: Harshit Sidhwa

# } Driver Code Ends