class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(), n2=s2.size(), n3=s3.size();
        if (n1+n2!=n3) return 0;
        vector<vector<int>> dp(n1+1 , vector<int>(n2+1, -1));
        function<int(int, int)> dfs=[&](int i, int j)->int
        {
            if (i==n1 && j==n2) return dp[i][j]=1;
            if (dp[i][j]!=-1) return dp[i][j];
            int ch_s1, ch_s2;
            if (i<n1 && s1[i]==s3[i+j]) ch_s1=dfs(i+1,j);
            if (j<n2 && s2[j]==s3[i+j]) ch_s2=dfs(i,j+1);
            return dp[i][j]=ch_s1||ch_s2;
        };
        return dfs(0, 0)!=0;
    }
};