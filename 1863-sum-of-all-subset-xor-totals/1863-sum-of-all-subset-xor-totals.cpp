class Solution {
public:
    int xorSubsets(int index, std::vector<int>& nums, int val) {
        if (index == nums.size()) return val;
        int include = xorSubsets(index + 1, nums, val ^ nums[index]);
        int exclude = xorSubsets(index + 1, nums, val);
        return include + exclude;
    }

    int subsetXORSum(std::vector<int>& nums) {
        return xorSubsets(0, nums, 0);
    }
};