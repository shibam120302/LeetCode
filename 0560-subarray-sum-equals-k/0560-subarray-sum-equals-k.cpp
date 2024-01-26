#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int sum = 0;

        // HashMap to store cumulative sum frequencies
        std::unordered_map<int, int> sumFreq;

        // Initialize with 0 sum frequency to handle subarrays starting from the beginning
        sumFreq[0] = 1;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];

            // Check if there exists a cumulative sum (sum - k) in the hashmap
            // If yes, add its frequency to the count
            if (sumFreq.find(sum - k) != sumFreq.end()) {
                count += sumFreq[sum - k];
            }

            // Update the cumulative sum frequency in the hashmap
            sumFreq[sum]++;
        }

        return count;
    }
};
