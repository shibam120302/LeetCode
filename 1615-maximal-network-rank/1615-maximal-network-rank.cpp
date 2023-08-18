class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> vec(n);
        int maxi = 0;
        for (auto x : roads) {
            vec[x[0]].push_back(x[1]);
            vec[x[1]].push_back(x[0]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = vec[i].size() + vec[j].size();
                if (find(vec[i].begin(), vec[i].end(), j) != vec[i].end()) rank--;
                maxi = max(maxi, rank);
            }
        }
        return maxi;
    }
};
