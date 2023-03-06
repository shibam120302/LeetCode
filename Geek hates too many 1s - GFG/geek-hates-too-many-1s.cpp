//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {

  public:
    int noConseBits(int n) {
        int set[35];

        for (int j = 0; j < 35; j++) set[j] = 0;

        for (int j = 30; j >= 0; j--) {
            if ((1 << j) & n) {
                set[j] = 1;
            }
        }
        int fin_ans = 0;
        for (int j = 30; j >= 2; j--) {
            if (set[j] == 1) {
                fin_ans |= (1 << j);
                if (set[j - 1] == 1) {
                    set[j - 2] = 0;
                }
            }
        }
        if (set[1] == 1) fin_ans |= 2;
        if (set[0] == 1) fin_ans |= 1;

        return fin_ans;
    }
};



//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends