//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int maxInstance(string s){
        vector<int> v(26,0);
        for(int i=0;i<s.length();i++){
            v[s[i]-'a']++;
        }
        int ans=min({v['b'-'a'],v['a'-'a'],v['l'-'a']/2,v['o'-'a']/2,v['n'-'a']});
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends