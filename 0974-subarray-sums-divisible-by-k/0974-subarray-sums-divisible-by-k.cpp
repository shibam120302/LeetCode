int buckets[10001];

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        memset(buckets, 0, sizeof(int)*k);
        buckets[0] = 1; // empty array
        int sum = 0, res = 0;
        for (int i: nums) {
            sum = ((sum + i) % k + k ) % k;
            if (buckets[sum]) { res += buckets[sum]; }
            ++buckets[sum];
        }
        return res;
    }
};