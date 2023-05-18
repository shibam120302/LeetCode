class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> set;
        for(int i=0; i<n; i++) set.insert(i);
        for(auto& it: edges){
            set.erase(it[1]);
        }
        return vector<int>(set.begin(), set.end());
    }
};