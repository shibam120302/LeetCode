class Solution {
public:
    struct DSU {
        vector<int> e;
        DSU (int n) {e = vector<int> (n, -1);}
        int get (int x) {return e[x] < 0 ? x : e[x] = get(e[x]);}
        bool same_set(int a, int b) { return get(a) == get(b); } // Not needed for this question
        int size(int x) { return -e[get(x)]; } // Not needed for this question
        bool unite (int x, int y) {
            x = get(x), y = get(y);
            if (x == y) return false;
            if (e[x] > e[y]) swap(x, y);
            e[x] += e[y];
            e[y] = x;
            return true;
        }
    };
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j]) {
                    dsu.unite(i, j);
                }
            }
        }
        int ans = 0;
        for (auto &x : dsu.e) {
            if (x < 0) {
                ans++;
            }
        }
        return ans;
    }
};