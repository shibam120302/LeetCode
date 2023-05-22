//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int N, vector<int> p){
        // code here
        
        int g[N + 1] = {0};
        
        for (int i = 1; i < p.size(); i++) {
            g[p[i]]++;
            g[i]++;
        }
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (g[i] == 1)
                cnt++;
        }
        
        cnt = N - cnt;
        
        return max(cnt - 1, 0);
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends