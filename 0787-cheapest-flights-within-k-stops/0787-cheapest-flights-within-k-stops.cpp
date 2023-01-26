class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>>adj[n];
        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<int>v(n, 1e9);
        v[src]=0;
        queue<pair<int, pair<int, int>>>q;
        q.push({src, {0, 0}});
        while(!q.empty()){
            int pos=q.front().first, wt=q.front().second.first, cnt=q.front().second.second;
            q.pop();
            for(auto it: adj[pos]){
                if(wt+it[1]<v[it[0]]){
                    if(cnt<=k){
                        v[it[0]]=it[1]+wt;
                        q.push({it[0], {wt+it[1], cnt+1}});
                    }
                }
            }
        }
        if(v[dst]==1e9){return -1;}
        return v[dst];
    }
};