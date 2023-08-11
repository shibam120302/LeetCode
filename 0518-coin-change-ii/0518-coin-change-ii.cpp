class Solution {
private:

    int helper(int amount, int index, vector<int> &coins, vector<vector<int>> &dp){

        if(index >= coins.size()) return 0;

        if(amount == 0) return 1;

        if(dp[amount][index] != -1) return dp[amount][index];

        int answer = 0;

        for(int i = index ; i < coins.size(); i++){
            if(amount >= coins[i]){
                answer += helper(amount - coins[i], i, coins, dp);
            }
        }

        return dp[amount][index] = answer;

    }

public:
    int change(int amount, vector<int>& coins) {
        // Intution
        // The idea in here is really very simple. We know that this prob is similar to combinations sum one.
        // Sorting to perform faster
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        sort(coins.rbegin(), coins.rend());
        int size = coins.size();
        vector<vector<int>> dp(amount + 1, vector<int> (size + 1, -1));
        return helper(amount, 0, coins, dp);

    }
};