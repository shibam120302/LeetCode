class Solution {
public:
    void dfs(int i,int j, vector<vector<int>> &grid,int &count){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0){
            return;
        }
        count++;
        grid[i][j]=0;
        dfs(i-1,j,grid,count);
        dfs(i,j+1,grid,count);
        dfs(i,j-1,grid,count);
        dfs(i+1,j,grid,count);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int c=0;
                    dfs(i,j,grid,c);
                    count=max(count,c);
                }
            }
        }
        return count;
    }
};