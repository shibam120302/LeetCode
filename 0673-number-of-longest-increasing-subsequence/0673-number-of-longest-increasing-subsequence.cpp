class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> lengths(n, 1);  // Length of LIS ending at each index
        vector<int> counts(n, 1);   // Number of LIS ending at each index

        int max_length = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (lengths[i] == lengths[j] + 1) {
                        counts[i] += counts[j]; // Another LIS ending at the same index
                    } else if (lengths[i] < lengths[j] + 1) {
                        lengths[i] = lengths[j] + 1; // Update length
                        counts[i] = counts[j];      // Reset count for the new length
                    }
                }
            }

            max_length = max(max_length, lengths[i]);
        }

        int result = 0;

        for (int i = 0; i < n; ++i) {
            if (lengths[i] == max_length) {
                result += counts[i]; // Sum counts of LIS with the maximum length
            }
        }

        return result;
    }
};

