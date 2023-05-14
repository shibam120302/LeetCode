class Solution {
public:
    
     int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b);}
    
    int f(vector<int>& nums, vector<vector<int>>& Gcd, int mask, int itr, vector<vector<int>> &dp ) {
        int n = nums.size();
        if(mask == 0) {   // no nums left
            return 0;
        }
        if(dp[itr][mask] != -1)    
        return dp[itr][mask];
      int answer=0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                   if( (mask & (1<<i)) && (mask & (1 << j)) ) {
                    answer = max(answer, Gcd[i][j] * itr + f(nums, Gcd, mask ^(1<<i)^ (1<<j), itr+1, dp));
                   }
              }
        }
      return  dp[itr][mask] = answer; 
    }  
    
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> Gcd(n, vector<int>(n,-1));
        //precalculate all pair gcd
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                Gcd[i][j] = Gcd[j][i] = gcd(nums[i], nums[j]);
            }
        }
        //create an dp array of bitmask and i (here named itr)
        vector<vector<int>> dp(n,vector<int>((1<<n), -1));
       return f(nums, Gcd, (1<<n)-1, 1, dp);
       
    }
};