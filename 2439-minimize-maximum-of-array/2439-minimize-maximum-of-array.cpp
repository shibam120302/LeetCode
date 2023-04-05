class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long int ans = nums[0];
        long long int i;
        long long int sum = nums[0];
        for(i=1;i<nums.size();i++)
        {
            sum += nums[i];
            //Taking average of numbers from index 0 to i
            ans = max(ans,(sum+i)/(i+1));
        }
        return ans;
    }
};