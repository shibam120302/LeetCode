class Solution {
public:
    int maxProductDifference(std::vector<int>& nums) {
        // Sort the array in non-decreasing order
        std::sort(nums.begin(), nums.end());

        // Calculate the product difference using the two smallest and two largest numbers
        int n = nums.size();
        int productDiff = (nums[n - 1] * nums[n - 2]) - (nums[0] * nums[1]);

        return productDiff;
    }
};