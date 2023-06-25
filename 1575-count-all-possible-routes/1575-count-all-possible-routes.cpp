class Solution {
    vector<vector<int>> dp;
    int n;
    int finish;

    int solve(vector<int>& locations, int currCity, int remainingFuel) {
        if (remainingFuel < 0) {
            return 0;
        }
        if (dp[currCity][remainingFuel] != -1) {
            return dp[currCity][remainingFuel];
        }

        int ans = (currCity == finish) ? 1 : 0;
        for (int nextCity = 0; nextCity < n; nextCity++) {
            if (nextCity != currCity) {
                ans = (ans + solve(locations, nextCity,
                    remainingFuel - abs(locations[currCity] - locations[nextCity]))) % 1000000007;
            }
        }

        return dp[currCity][remainingFuel] = ans;
    }

public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size();
        dp.resize(n, vector<int>(fuel + 1, -1));
        this->finish = finish;

        return solve(locations, start, fuel);
    }
};