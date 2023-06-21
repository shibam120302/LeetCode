class Solution {
public:
    long long calculateSum(vector<int>& nums, vector<int>& cost, long long target) {
        long long res = 0;
        for (int i = 0; i < (int) nums.size(); ++i) {
            res += abs(nums[i] - target) * cost[i];
        }
        return res;
    }


    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long s = *min_element(nums.begin(), nums.end());
        long long e = *max_element(nums.begin(), nums.end());
        while (s < e) {
            long long mid = (s + e) / 2;
            long long leftSum = calculateSum(nums, cost, mid);
            long long rightSum = calculateSum(nums, cost, mid + 1);
            if (leftSum < rightSum) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        return calculateSum(nums, cost, s);
    }
}; 