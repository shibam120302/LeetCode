//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) {
	    // A vector of pairs. Every element of
	    // pair contains array element and its
	    // index
	    vector<pair<int, int>> v;

	    // Put all elements and their index in
	    // the vector
	    for (int i = 0; i < n; i++) v.emplace_back(arr[i], i);

	    // Sort the vector by array values
	    sort(v.begin(), v.end());

	    // Put indexes of modified vector in arr[]
	    for (int i = 0; i < n; i++) arr[v[i].second] = i;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.convert(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends