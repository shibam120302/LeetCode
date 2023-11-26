class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        int area=0;
        for(int i=0;  i<m; i++){
            #pragma unroll
            for(int j=0; j<n; j++){
                if (matrix[i][j]!=0 && i>0)
                    matrix[i][j]+=matrix[i-1][j];
            }
            auto row=matrix[i];
            sort(row.begin(), row.end());
            #pragma unroll
            for(int i=0; i<n; i++)
                area=max(area, row[i]*(n-1-i+1));
        }
        return area;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();