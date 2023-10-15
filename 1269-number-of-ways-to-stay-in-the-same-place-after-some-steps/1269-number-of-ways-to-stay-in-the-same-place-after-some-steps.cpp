class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int m = 1e9 + 7;
        arrLen = min(arrLen, steps + 1);
        vector<vector<int>> dp(arrLen, vector<int>(steps + 1, 0));
        dp[0][0] = 1;

        for (int remain = 1; remain <= steps; remain++) {
            for (int curr = 0; curr < arrLen; curr++) {
                int ans = dp[curr][remain - 1];

                if (curr > 0) {
                    ans = (ans + dp[curr - 1][remain - 1]) % m;
                }

                if (curr < arrLen - 1) {
                    ans = (ans + dp[curr + 1][remain - 1]) % m;
                }

                dp[curr][remain] = ans;
            }
        }

        return dp[0][steps];
    }
};