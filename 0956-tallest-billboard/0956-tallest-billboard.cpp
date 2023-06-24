class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int sum=accumulate(rods.begin(),rods.end(),0)/2;
        vector<vector<int>> dp(rods.size()+1,vector<int>(sum+1,-100));
        return solve(rods,0,0,0,dp);
    }
    int solve(vector<int>&rods,int ind,int left,int right,vector<vector<int>>&dp){
        //bases case 1
        if(left>dp[0].size()-1 || right>dp[0].size()-1){
            return -1;//here -1 means we cant reach the solution or left can be equal to right
        }
        //base case 2
        if(ind>=rods.size()){
            if(left==right){
                return left;//the length we can achieve
            }
            return -1;
        }
        //ignore for now move to next part
        if(dp[ind][abs(left-right)]!=-100){
            //but we can give back the margin but the highest amount we have collected 
            int f=0;
            if(dp[ind][abs(left-right)]!=-1){
                f=max(left,right);
            }
            return dp[ind][abs(left-right)]+f;            
        }
        //there are three choices one to leave the rod , add to left sum,add to right sum
        int a=solve(rods,ind+1,left,right,dp);
        int b=solve(rods,ind+1,left+rods[ind],right,dp);
        int c=solve(rods,ind+1,left,right+rods[ind],dp);
        int d=max({a,b,c});

        //here we are storing the margin of highest-max(left,right)
        //but in some cases d will be -1 i.e answer is not achievable
        dp[ind][abs(left-right)]=max(-1,d-max(left,right));

        //but we don't want give back the margin but the highest amount we have collected 
        int e=0;
        if(dp[ind][abs(left-right)]!=-1){
            e=max(left,right);
        }
        return dp[ind][abs(left-right)]+e;
    }
};