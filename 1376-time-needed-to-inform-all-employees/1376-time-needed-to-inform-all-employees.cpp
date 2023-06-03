class Solution {
public:
    vector<int> g[100005];
    int vis[100005], dis[100005];
    void bfs(int s, vector<int>& informTime) 
    {
        queue<int> q;
        vis[s] = 1;
        dis[s] = 0;
        q.push(s);
        while(!q.empty()) 
        {
            int u = q.front();
            q.pop();
            for(auto v: g[u]) 
            {
                if(!vis[v])
                 {
                    vis[v] = 1;
                    dis[v] = dis[u] + informTime[u];
                    q.push(v);
                }
            }
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        for(int i=0; i<n; i++) 
        {
            if(manager[i] != -1) g[manager[i]].push_back(i);
        }
        bfs(headID, informTime);
        int ans = 0;
        for(int i=0; i<n; i++) ans = max(ans, dis[i]);
        return ans;
    }
};