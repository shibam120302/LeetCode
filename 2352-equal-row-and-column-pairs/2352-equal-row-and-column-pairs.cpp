class Solution {
public:
    bool isEqual(int r, int c, vector<vector<int>>& m) {
        int n = m.size();
        for (int i = 0; i < n; i++) {
            if (m[r][i] != m[i][c]) return false;
        }
        return true;
    }
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isEqual(i, j, grid))
                    cnt++;
            }
        }
        return cnt;
    }
};