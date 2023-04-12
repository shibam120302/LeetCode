//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        sort(arr.begin(),arr.begin()+(n/2));
        sort(arr.begin()+(n/2),arr.end());
        int ans=0;
        int right=n/2;
        for(int left=0;left<n/2;left++){
            while(right<n && arr[left]>=5*arr[right]){
                right++;
            }
            ans+=right-n/2;
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends