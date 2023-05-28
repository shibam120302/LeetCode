class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> v(cuts.size(), vector<int>(cuts.size(), -1));
        return dfs(cuts, v, 0, cuts.size() - 1);
    }
    
    int dfs(vector<int>& c, vector<vector<int>>& v, int l, int r){
        if (l == r - 1) return 0;
        if (v[l][r] != -1) return v[l][r];
        int sum = c[r] - c[l], smallest = INT_MAX;
        for (int i = l + 1; i < r; ++i)
            smallest = min(smallest, dfs(c, v, l, i) + dfs(c, v, i, r));
        return v[l][r] = sum + smallest;
    } 
};