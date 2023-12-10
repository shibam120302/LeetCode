class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        // Create Transpose Matrix
        vector<vector<int>> ans(col, vector<int>(row, 0));
        // Insert In Transpose Matrix
        for (int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                ans[j][i] = matrix[i][j];

        return ans;
    }
};