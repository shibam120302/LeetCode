class Solution {
public:
    void solve(int k,int n,vector<int> tmp,vector<vector<int>> &ans,int s){
        if(n==0&&k==0){
            ans.push_back(tmp);
            return;
        }
        if(n==0)return;
        if(k==0)return;
        for(int i = s; i <= 9; i++){
            tmp.push_back(i);
            solve(k-1,n-i,tmp,ans,i+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if(k>=n || n==1){
            return ans;
        }
        vector<int> tmp;
        solve(k,n,tmp,ans,1);
        return ans;
    }
};