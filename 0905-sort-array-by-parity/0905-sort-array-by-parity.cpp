class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) if(nums[i] % 2 == 0) result.push_back(nums[i]);
        for(int i = 0; i < nums.size(); i++) if(nums[i] % 2 == 1) result.push_back(nums[i]);
        return result;
    }
};