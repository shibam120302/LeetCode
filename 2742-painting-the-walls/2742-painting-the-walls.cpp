class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        int memo[n][2*n+2];
        memset(memo, -1, sizeof memo);
        
        int INF = 1e9;
        
        function<int(int,int)> solve = [&](int i, int j) {
            // base cases
            if(i == n) {
                if(j < 0) return INF;
                return 0;
            }
            
            if(memo[i][n+j] != -1) return memo[i][n+j];
            
            int result = INF;
            
            // use paid painter
            result = min(result, cost[i] + solve(i+1, min(n-1,j+time[i])));
            
            // use free painter
            result = min(result, solve(i+1, j-1));
            
            return memo[i][n+j] = result;
        };
        
        return solve(0, 0);
    }
};