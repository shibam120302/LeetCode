//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      long long int ans = n * 1LL * n;
      vector<bool> row(n+1,false);
      vector<bool> col(n+1,false);
      int r = n, c = n;
      vector<long long int> v;
      for(int i=0;i<k;i++) {
        int x = arr[i][0];
        int y = arr[i][1];
        if (!row[x] && !col[y]) {
          ans = ans - c - r + 1;
          r--;
          c--;
        } else if (!row[x] && col[y]) {
          ans = ans - c;
          r--;
        } else if (row[x] && !col[y]) {
          ans = ans - r;
          c--;
        }
        v.push_back(ans);
        row[x] = col[y] = true;
      }  
      return v;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends