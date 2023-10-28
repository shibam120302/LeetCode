class Solution {
    int dfs(int i, int last, int n, vector<vector<int>> &dp, int mod) {
        if(i == n) return 1;
        if(dp[i][last] != -1) return dp[i][last];

        long long ans = 0;
        if(last == 0) {
            for(int j=1; j<=5; j++) ans += dfs(i + 1, j, n, dp, mod);
        }
        else if(last == 1) ans += dfs(i + 1, 2, n, dp, mod);
        else if(last == 2) ans += dfs(i + 1, 1, n, dp, mod) + dfs(i + 1, 3, n, dp, mod);
        else if(last == 3) {
            for(int j=1; j<=5; j++) {
                if(last != j) ans += dfs(i + 1, j, n, dp, mod);
            }
        }
        else if(last == 4) ans += dfs(i + 1, 3, n, dp, mod) + dfs(i + 1, 5, n, dp, mod);
        else ans += dfs(i + 1, 1, n, dp, mod);

        return dp[i][last] = ans % mod;
    }
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n, vector<int> (6, -1));
        return dfs(0, 0, n, dp, 1e9 + 7);
    }
};
