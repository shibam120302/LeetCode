class Solution {
private:
    pair<bool, int> dfs(vector<vector<int>>& grid, int i, int j) {
        // Out of bounds are not considered as moves
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size()) return {false, 0};
        
        // Return 0 if it's sea or a visited cell
        if (grid[i][j] == 0 || grid[i][j] == 2) return {true, 0};

        // Mark current land as visited
        grid[i][j] = 2;

        // Recursively explore 4 directions
        auto [isTopValid, topMoves] = dfs(grid, i - 1, j);
        auto [isBottomValid, bottomMoves] = dfs(grid, i + 1, j);
        auto [isLeftValid, leftMoves] = dfs(grid, i, j - 1);
        auto [isRightValid, rightMoves]= dfs(grid, i, j + 1);

        // If it's valid, return number of moves found
        if(isTopValid && isBottomValid && isLeftValid && isRightValid) {
            return {true, 1 + (leftMoves + rightMoves + topMoves + bottomMoves)};
        }

        return {false, 0};
    }

public:
    // T:O(mn), S:O(mn)
    int numEnclaves(vector<vector<int>>& grid) {
        int moves = 0;

        // Go through all cells in a grid
        for(int i = 0; i < grid.size(); i++) { // O(n)
            for(int j = 0; j < grid[i].size(); j++) { // O(m)
                if(grid[i][j] == 1) {
                    auto [isValid, numMoves] = dfs(grid, i, j);

                    // Increment moves if it's valid
                    if(isValid) moves += numMoves;
                }
            }
        }
        return moves;
    }
};