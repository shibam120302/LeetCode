class Solution {
public:    

        int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
		// variable to store sum of array nums
        int sm=0;
        for(auto x : nums)  sm+=x;
		// base cases , sum should be greater then target and difference should always be even for equal subsets
        if(sm<target || (sm-target)%2!=0)   return 0;
        // finding the value of other subset
        int sm2 = (sm-target)/2;
		// 2D vector to store the sub-problem solutions
        vector<vector<int>> t(n+1,vector<int>(sm2+1,0));
		// 0 elements required to get 0 sum
        t[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=sm2;j++)
            {
				// if value is less than j then we have chance to include it 
                if(nums[i-1]<=j)
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
				// we use the earlier same solution for it
                else
                    t[i][j] = t[i-1][j];
            }
        }
		// to have target we have t[n][sm2] ways
        return t[n][sm2];
        
    }
    
};