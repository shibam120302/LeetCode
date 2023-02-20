//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int countPaths(int N){
        // code here 
        long long int mod=1000000007;
        long long int low=1l,high=0l;
        long long int tlow=1l,thigh=0l;
        for(int i=2;i<=N;i++)
        {
            high=(3*tlow)%mod;
            low=(((2*tlow)%mod)+thigh)%mod;
            tlow=low;
            thigh=high;
        }
        return (int)high;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends