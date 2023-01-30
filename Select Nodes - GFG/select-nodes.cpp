//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    void dfs(vector<int> adj[], int src, int par, vector<int> val[]) {
        for(int v: adj[src])
            if(v!=par)
                dfs(adj,v,src,val);

        for(int v: adj[src])
        {
            if(v!=par)
            {
                val[src][0] += val[v][1];
                val[src][1] += min(val[v][1],val[v][0]);
            }
        }
    }

    int countVertex(int N, vector<vector<int>>edges){
        vector<int> adj[N+1];
        for(int i=0; i<N-1; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> val[N+1];
        for(int i=1; i<=N; i++)
        {
            vector<int> x = {0, 1};
            val[i] = x;
        }

        dfs(adj,1,1,val);

        return min(val[1][0],val[1][1]);
    }
};




//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends