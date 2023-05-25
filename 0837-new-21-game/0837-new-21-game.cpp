class Solution {
public:
    double new21Game(int n, int k, int mx) {
        if (k == 0 || n >= k + mx) return 1.0;
        vector<double> dp(n+1);
        dp[0] = 1.0;
        double pref = 1.0;
        double res = 0.0; 
        for (int i = 1; i <= n; i++){
            dp[i] = pref / mx;
            if (i < k) pref += dp[i];
            if (i >= mx && i < k + mx) pref -= dp[i - mx];
            if (i >= k) res += dp[i];
        }
        return res;
    }
};