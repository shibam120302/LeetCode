//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    // Helper function to find LIS
    int LongestIncreasingSubsequenceLength(vector<int>& v)  
    {  
        if (v.size() == 0)  
            return 0;  
      
        vector<int> tail(v.size(), 0);  
        int length = 1; // always points empty slot in tail  
      
        tail[0] = v[0];  
          
        for (int i = 1; i < v.size(); i++) {  
      
                // Do binary search for the element in  
                // the range from begin to begin + length 
            auto b = tail.begin(), e = tail.begin() + length; 
            auto it = lower_bound(b, e, v[i]);  
                  
            // If not present change the tail element to v[i]  
            if (it == tail.begin() + length) 
                tail[length++] = v[i];  
            else   
                *it = v[i];  
        }  
      
        return length;  
    }  

    int removeStudents(int H[], int N) {
        
        vector<int> arr;
        for(int i=0; i<N; i++)
            arr.push_back(H[i]);
            
        int ans = N - LongestIncreasingSubsequenceLength(arr);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends