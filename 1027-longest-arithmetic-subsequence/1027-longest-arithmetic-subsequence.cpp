class Solution {
public:
    vector<vector<int>> dp;
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        dp=vector<vector<int>>(n,vector<int>(1001,1));

        int ans=1;
        for(int i=1;i<n;i++) for(int j=0;j<i;j++){
            int d=nums[i]-nums[j];
            if(d<0) d=500-d;
            dp[i][d]=1+dp[j][d];
            ans=max(ans,dp[i][d]);
        }

        return ans;
    }
};