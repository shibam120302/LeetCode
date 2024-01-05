class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);

        for(int i=0;i<n;i++){
            int temp = 0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    temp=max(temp, dp[j]);
                }
            }
            dp[i] = 1 + temp;
        }

        return *max_element(dp.begin(),dp.end());
    }
};