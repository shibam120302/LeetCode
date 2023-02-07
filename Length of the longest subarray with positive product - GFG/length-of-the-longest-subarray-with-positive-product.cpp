//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        int maxLength(vector<int> &arr,int n){
            int pos = 0,neg = 0,ans = 0;
            for(int i = 0;i<n;i++){
                if(arr[i]==0){
                    pos = 0;
                    neg = 0;
                } else if (arr[i] > 0){
                    pos+=1;
                    if(neg > 0){
                        neg+=1;
                    }
                } else if(arr[i]<0){
                    int temp = pos;
                    if(neg > 0){
                        pos = 1+neg;
                    } else {
                        pos = 0;
                    }
                    neg = 1 + temp;
                }
                ans = max(ans,pos);
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends