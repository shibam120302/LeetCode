class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long int sum = 0;
        int cnt = 0;
        int i = 0;
        while(sum < n)
        {
            if(i<nums.size() && nums[i] <= sum+1)
            {
                sum = sum + nums[i++];
            }
            else
            {
                cnt++;
                sum = sum * 2 + 1;
            }
        }
        return cnt;
    }
};