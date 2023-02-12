class Solution {
public:
    long long solve(int node,int parent,int seats,long long& ans,vector<int> adj[]){
        long long count=1;
        for(auto &i:adj[node]){
            if(i != parent){
                count+=solve(i,node,seats,ans,adj);
            }
        }
        long long cost=ceil(count/(1.0*seats));
        if(node != 0) ans+=cost;
        return count;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int N=roads.size();
        vector<int> adj[N+1];
        for(auto &i:roads){
            int u=i[0],v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long ans=0;
        long long res=solve(0,-1,seats,ans,adj);
        return ans;
    }
};