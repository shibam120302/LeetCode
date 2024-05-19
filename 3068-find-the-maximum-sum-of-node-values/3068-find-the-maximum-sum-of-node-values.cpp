class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long res = 0;
        int changes = 0;
        int minDiff = INT_MAX;
        
        for (int num : nums) {
            int xorNum = num ^ k;

            if (num < xorNum) {
                changes++;
                res += xorNum;
            } else {
                res += num;
            }

            minDiff = min(minDiff, abs(num - xorNum));
        }

        if (changes % 2 == 1)
            return res - minDiff;
        else
            return res;
    }
};