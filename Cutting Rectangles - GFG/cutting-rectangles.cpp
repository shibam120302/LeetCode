//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int gcd(long long int n, long long int m){
        if(m == 0)
            return n;
        return gcd(m, n%m);
    }

    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        long long int x = gcd(L, B);
        vector<long long int> ans;
        ans.push_back((L*B)/(x*x));
        ans.push_back(x);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int L, B;
        cin>>L>>B;
        
        Solution ob;
        vector<long long int> ans = ob.minimumSquares(L, B);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}
// } Driver Code Ends