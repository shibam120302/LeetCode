struct HeapNode {
    int x;
    int y;
    int keys;
};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> seen(m, vector<vector<int>>(n, vector<int>(64, 0)));
        int all_keys = 0;
        HeapNode start;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '@'){
                    start.x = i;
                    start.y = j;
                    start.keys = 0;
                    seen[i][j][0] = 1;
                } else if(islower(grid[i][j])){
                    all_keys |= (1 << (grid[i][j] - 'a'));
                }
            }
        }
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        queue<HeapNode> q;
        q.push(start);
        int step = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr = q.front();
                q.pop();
                if(curr.keys == all_keys) return step;
                for(const auto& dir : dirs){
                    int nx = dir[0] + curr.x;
                    int ny = dir[1] + curr.y;
                    int nkeys = curr.keys;
                    if(nx <0 || nx >= m || ny <0 || ny >=n || grid[nx][ny] == '#') continue;
                    char c = grid[nx][ny];
                    if(isupper(c) && !(curr.keys & 1 << (c - 'A'))) continue;
                    if(islower(c)) nkeys |= (1 << (c - 'a'));
                    if(seen[nx][ny][nkeys]) continue;
                    q.push({nx, ny, nkeys});
                    seen[nx][ny][nkeys] = 1;
                }
            }
            step++;
        }
        return -1;
    }
};