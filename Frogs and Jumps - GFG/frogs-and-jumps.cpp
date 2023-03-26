//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        
        vector<int> leaveStatus (leaves + 1, 0);
		for (int i = 0; i < N; i++) {
			if (frogs[i] <= leaves && leaveStatus[frogs[i]] == 0) {
				for (int j = frogs[i]; j <= leaves; j += frogs[i]) {
					leaveStatus[j] = 1;
				}
			}
		}
		int leafCount = leaves;
		for (int i : leaveStatus) {
			if (i) {
				leafCount--;
			}
		}
		return leafCount;
    }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends