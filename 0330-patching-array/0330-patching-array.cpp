class Solution {
public:
    int minPatches(std::vector<int>& nums, int n) {
    long long patch = 0;
    int count = 0;
    int index = 0;
    while (patch < n) {
        if (index < nums.size() && patch + 1 >= nums[index]) {
            patch += nums[index];
            index++;
        } else {
            patch += (patch + 1);
            count++;
        }
    }

    return count;
}
};