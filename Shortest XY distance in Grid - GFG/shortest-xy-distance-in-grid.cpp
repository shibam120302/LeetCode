//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        int dist[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                dist[i][j] = 1e9;
            }
        }

        // check top and left
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 'X')
                    dist[i][j] = 0;
                else {
                    if (i > 0) dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                    if (j > 0) dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }

        // check bottom and right
        for (int i = N - 1; i >= 0; i--) {
            for (int j = M - 1; j >= 0; j--) {
                if (grid[i][j] == 'X')
                    dist[i][j] = 0;
                else {
                    if (i < N - 1)
                        dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                    if (j < M - 1)
                        dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
                }
            }
        }

        int ans = 1e9;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 'Y') ans = min(ans, dist[i][j]);
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends