class Solution {
public:
    bool isValid(int i , int j , int r , int c , vector<vector<int>>& grid , vector<vector<int>>& vis){
        return (i >= 0 && i < r && j >= 0 && j < c && grid[i][j] == 0 && vis[i][j] == 0);
    }
    bool dfs(vector<vector<int>>& grid , int i , int j , vector<vector<int>> & vis){
        int r = grid.size();
        int c = grid[0].size();
        if(grid[i][j] == 1) return false;
        if(i == r-1) return true;
        vis[i][j] = 1;
        bool v1 = false , v2 = false , v3 = false , v4 = false;
        if(isValid(i+1 , j , r , c , grid , vis)){
            v1 = dfs(grid , i+1 , j , vis);
        }
        if(isValid(i-1 , j , r , c , grid , vis)){
            v2 = dfs(grid , i-1 , j , vis);
        }
        if(isValid(i , j+1 , r , c , grid , vis)){
            v3 = dfs(grid , i , j+1 , vis);
        }
        if(isValid(i , j-1 , r , c , grid , vis)){
            v4 = dfs(grid , i , j-1 , vis);
        }
        return v1 || v2 || v3 || v4;
    }
    vector<vector<int>> gridmake(vector<vector<int>>& cell , int mid , int row , int col){
        vector<vector<int>> grid(row , vector<int>(col , 0));
        for(int i = 0 ; i <= mid ; i++){
            grid[cell[i][0] - 1][cell[i][1] - 1] = 1;
        }
        return grid;
    }
    vector<vector<int>> vistedMake(vector<vector<int>>& cell , int mid , int row , int col){
        vector<vector<int>> grid(row , vector<int>(col , 0));
        for(int i = 0 ; i <= mid ; i++){
            grid[cell[i][0] - 1][cell[i][1] - 1] = 1;
        }
        return grid;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int lo = 0 , //good
        hi = cells.size() - 1; // bad
        int ans = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            auto grid = gridmake(cells , mid , row , col);
            auto vist = vistedMake(cells , mid , row , col);
            bool res = false; 
            for(int i = 0 ; i < col ; i++){
                res |= dfs(grid , 0 , i , vist); // or for kahi bhi mil jaye true agar
                if(res) break;
            }
            if(res){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans + 1;
    }
};