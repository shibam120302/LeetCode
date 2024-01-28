class Solution {
public:

int subarraySum(vector<int>& nums, int k) {

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int cnt = 0, curr_sum = 0;
        unordered_map<int, int>mp;
        for(int i=0; i<nums.size(); i++)
        {
            curr_sum += nums[i];

            if(curr_sum == k)cnt++;
            if(mp.find(curr_sum - k) != mp.end())
            {
                cnt += mp[curr_sum - k];
            }

            mp[curr_sum]++;
        }

        return cnt;
    }

    
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {

        int count=0;
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0; i<n; i++){
			
            vector<int> sum(m, 0);
            for(int j=i; j<n; j++){
                for(int k=0; k<m; k++){
                    sum[k] += mat[j][k];
                }
                count += subarraySum(sum, target);
            }
        }
       
    return count;
        
    }
};