class Solution {
public:
    string stoneGameIII(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixSum(nums);
        for(int i=1;i<n;i++){
            prefixSum[i]+=prefixSum[i-1];
        }
        vector<int> dp(n,-5e7);
        
        for(int i=0; i<n; i++){
            dp[i]= getPrefixSum(prefixSum,n-1-i,n-1) - min({
               i-1>=0?dp[i-1]:0,
               i-2>=0?dp[i-2]:0,
               i-3>=0?dp[i-3]:0
            });
        }
        
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(dp.back()*2>sum) return "Alice";
        else if(dp.back()*2==sum) return "Tie";
        else return "Bob";
    }
    
    int getPrefixSum(vector<int>& prefixSum, int l, int r){
        return prefixSum[r] - (l==0?0:prefixSum[l-1]);
    }
};