//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int valid(int N, int M, vector<vector<int>> A, int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < M && A[x][y] == 1;
    }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        queue<pair<int, pair<int, int>>> q;
        int vis[N][M];
        memset(vis, 0, sizeof(vis));
        q.push({0, {0, 0}});
        int xx[] = {0, 0, 1, -1};
        int yy[] = {-1, 1, 0, 0};
        int ans = -1;
        vis[0][0] = 1;
        while (!q.empty()) {
            auto r = q.front();
            q.pop();
            if (r.second.first == X and r.second.second == Y) {
                ans = r.first;
                break;
            }

            for (int i = 0; i < 4; i++) {
                if (!vis[r.second.first + xx[i]][r.second.second + yy[i]] and
                    valid(N, M, A, r.second.first + xx[i],
                          r.second.second + yy[i])) {
                    vis[r.second.first + xx[i]][r.second.second + yy[i]] = 1;
                    q.push({r.first + 1,
                            {r.second.first + xx[i], r.second.second + yy[i]}});
                }
            }
        }
        if (!A[0][0] || !A[X][Y]) ans = -1;
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends