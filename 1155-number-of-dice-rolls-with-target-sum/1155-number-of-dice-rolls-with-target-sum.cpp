class Solution {
public:
    int mod = 1e9+7;
    int solve(int n,int &k,int x,vector<vector<int>> &dp){
        if(n==0&&x==0)return 1;
        if(n<=0)return 0;
        if(dp[n][x] != -1)return dp[n][x];
        int ans = 0;
        for(int i = 1; i <= min(k,x); i++){
            ans = (ans+solve(n-1,k,x-i,dp))%mod;
        }
        return dp[n][x] = ans;
    }
    int numRollsToTarget(int n, int k, int x) {
        mod = 1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(x+1,-1));
        return solve(n,k,x,dp);
    }
};