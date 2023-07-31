class Solution {
public:
    string w1, w2;
    int n1, n2;
    vector<vector<int>> dp;
    
    int lcs(int x, int y){
        if (dp[x][y] != INT_MAX) return dp[x][y];
        if (x == n1 && y == n2) return dp[x][y] = 0;
        if (x == n1) return dp[x][y] = w2[y] + lcs(x, y+1);
        if (y == n2) return dp[x][y] = w1[x] + lcs(x+1, y);
        
        int sum;
        if (w1[x] == w2[y]) 
            sum = lcs(x+1, y+1);
        else 
            sum = min(lcs(x+1, y) + w1[x], lcs(x, y+1) + w2[y]);
        
        return dp[x][y] = sum;
    }

    int minimumDeleteSum(string s1, string s2) {
        n1 = s1.size();
        n2 = s2.size();
        w1 = s1;
        w2 = s2;
        dp.assign(n1+1, vector<int>(n2+1, INT_MAX));
        
        return lcs(0, 0);
    }
};