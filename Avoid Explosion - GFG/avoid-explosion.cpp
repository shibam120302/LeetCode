//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int rnk[10005], par[10005];
    void make_set(int n) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
            rnk[i] = 1;
        }
    }
    int find_set(int x) {
        if (par[x] == x) return x;
        return par[x] = find_set(par[x]);
    }
    void union_set(int a, int b) {
        int p1 = find_set(a);
        int p2 = find_set(b);

        if (p1 == p2) return;

        if (rnk[p1] > rnk[p2]) {
            par[p2] = p1;
            rnk[p1] += rnk[p2];
        } else {
            par[p1] = p2;
            rnk[p2] += rnk[p1];
        }
    }

    vector<string> avoidExplosion(vector<vector<int>> mix, int n,
                                  vector<vector<int>> danger, int m) {
        make_set(n + 1);
        vector<string> ans(n);
        for (int i = 0; i < n; i++) {
            int item1 = mix[i][0];
            int item2 = mix[i][1];
            int ok = 1;
            int p1 = find_set(item1);
            int p2 = find_set(item2);
            for (int j = 0; j < m; j++) {
                int par1 = find_set(danger[j][0]);
                int par2 = find_set(danger[j][1]);
                if (max(par1, par2) == max(p1, p2) and
                    min(par1, par2) == min(p1, p2)) {
                    ok = 0;
                    break;
                }
            }

            if (ok) {
                ans[i] = "Yes";
                union_set(p1, p2);
            } else {
                ans[i] = "No";
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mix(n, vector<int>(2));
        vector<vector<int>> danger(m, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> mix[i][0] >> mix[i][1];
        }

        for (int i = 0; i < m; i++) {
            cin >> danger[i][0] >> danger[i][1];
        }

        auto ans = sol.avoidExplosion(mix, n, danger, m);
        for (auto &val : ans) cout << val << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends