//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        unordered_map<int, int> frequency;
        unordered_set<int> distinctElements;
        int maxVal = 0;
        for (int i : arr) {
            distinctElements.insert(i);
            maxVal = max(i, maxVal);
            frequency[i]++;
        }
        unordered_set<int> specialNumbers;
        for (auto i : distinctElements) {
            for (int j = 2 * i; j <= maxVal; j += i) {
                if (distinctElements.find(j) != distinctElements.end()) {
                    specialNumbers.insert(j);
                }
            }
        }
        int ans = 0;

        for (auto ele : frequency) {
            if (ele.second > 1) {
                ans += ele.second;
            } else if (specialNumbers.find(ele.first) != specialNumbers.end()) {
                ans++;
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
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends