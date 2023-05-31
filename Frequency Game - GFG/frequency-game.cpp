//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        int mx=0,mn=1e9;
        for(auto it:mpp){
            if(it.second<mn){
                mn=it.second;
                mx=it.first;
            }
            else if(it.second==mn){
                mx=max(mx,it.first);
            }
        }
        return mx;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends