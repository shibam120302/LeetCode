class Solution {
public:
int dp[501][501];
int solve(int i,int j,vector<int> &nums1,vector<int> &nums2)
{
    int n=nums1.size();
    int m=nums2.size();
    if(i==n||j==m)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];

    return dp[i][j]=max(nums1[i]*nums2[j]+solve(i+1,j+1,nums1,nums2),max(solve(i+1,j,nums1,nums2),solve(i,j+1,nums1,nums2)));
}
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int max1=-1001;
        int min1=1001;
        int max2=-1001;
        int min2=1001;
       
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            min1=min(min1,nums1[i]);
            max1=max(max1,nums1[i]);
        }
         for(int i=0;i<m;i++)
        {
            min2=min(min2,nums2[i]);
            max2=max(max2,nums2[i]);
        }
        if((min1<0&&max1<0)&&(max2>0&&min2>0))
        return max1*min2;
        else if(min1>0||max2<0)
        return min1*max2;

        return max(solve(0,0,nums1,nums2),max(max2*min1,max1*min2));
        
    }
};