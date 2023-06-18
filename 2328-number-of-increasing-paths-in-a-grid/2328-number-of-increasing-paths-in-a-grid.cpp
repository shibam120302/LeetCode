class Solution {
public: 
    int mod = 1e9+7;
    vector<int> dir = {-1,0,1,0,-1};
    int dfs(int i, int j, vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp)
    {
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 1;
        for(int k=0;k<4;k++)
        {    
            int di = i + dir[k];
            int dj = j + dir[k+1];
            if(di >= 0 and di < m and dj >= 0 and dj < n and grid[i][j] < grid[di][dj])
                ans = (ans + dfs(di, dj, grid, m, n, dp))%mod;
        }
        return dp[i][j] = ans;
    }
    
    int countPaths(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        long ans=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                ans = (ans + dfs(i, j, grid, m, n, dp))%mod;
        } 
        return ans; 
    }
};