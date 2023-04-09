class Solution {
public:
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        set<int> vis;
        int n=colors.length();
        vector<int> adj[n];
        int indegree[n];
        memset(indegree, 0, sizeof(indegree));
        for(int i=0;i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0) q.push(i);
        }
        int visited[n];
        memset(visited, 0, sizeof(visited));
        int dp[n][26];
        memset(dp, 0,sizeof(dp));
        int ans = 0;
        while(!q.empty()){
            int ind = q.front();
            q.pop();
            dp[ind][colors[ind]-'a']++;
            visited[ind]++;
            for(int i=0; i<26; i++){
                ans = max(ans, dp[ind][i]);
            }
            for(auto i:adj[ind]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }else if(indegree[i]<0){
                    return -1;
                }
                for(int j=0; j<26;j++){
                    dp[i][j] = max(dp[i][j], dp[ind][j]);
                }
            }
        }
        for(int i=0; i<n;i++){
            if(!visited[i]) return -1;
        }
        return ans;
    }
};