class Solution {
    const int MOD = 1e9 + 7;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> DP(high + 1);
        int ans = 0;
        DP[0] = 1;
        for(int i = 1; i <= high; i++) {
            DP[i] = ((i >= zero? DP[i - zero]: 0) + (i >= one? DP[i - one]: 0)) % MOD;
            if(i >= low && i <= high)
                ans = (ans + DP[i]) % MOD;
        }
        return ans;
    }
};