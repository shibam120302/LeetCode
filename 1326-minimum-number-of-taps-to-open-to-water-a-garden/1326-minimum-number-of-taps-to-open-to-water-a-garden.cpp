class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int i,j;
        vector<int> dp(n+1,n+10);
        dp[0] = 0;
        for(int i = 0; i <= n; i++){
            for(j = max(0,i-ranges[i]+1); j<=min(n,i+ranges[i]); j++){
                dp[j] = min(dp[j],dp[max(i-ranges[i],0)]+1);
            }
        }
        return dp[n]>=n+2?-1:dp[n];
    }
};