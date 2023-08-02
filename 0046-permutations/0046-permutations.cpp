class Solution {
public:
    
    void solve(vector<int>& a, int idx, vector<int> &v, vector<vector<int>> &ans, vector<bool> &visited){
        int n=a.size();
        
        if(idx==n){
            ans.push_back(v);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                visited[i]=true;
                v.push_back(a[i]);
                
                solve(a,idx+1,v,ans,visited);
                
                v.pop_back();
                visited[i]=false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& a) {
        int n=a.size();
        
        vector<vector<int>> ans;
        vector<int> v;
        vector<bool> visited(n,false);
        
        solve(a,0,v,ans,visited);
        
        return ans;
    }
};