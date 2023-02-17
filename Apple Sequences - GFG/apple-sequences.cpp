//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        int start = 0, end = 0;
        int curr=0;
        int maxx=0;
        while(end<n){
            if(arr[end]=='A'){
                maxx=max(maxx, end-start+1);
            }
            if(arr[end]=='O'){
                curr++;
                if(curr>m){
                    while(start<end && arr[start]!='O')
                        start++;
                    start++;    
                }
                maxx=max(maxx, end-start+1);
            }
            end++;
        }
        return maxx;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends