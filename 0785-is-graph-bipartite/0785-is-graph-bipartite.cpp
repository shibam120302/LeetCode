class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public: 
    UnionFind(int size) {
        parent = vector<int>(size);
        rank = vector<int>(size);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    } 
    int find(int a) {
        if (parent[a] != a) parent[a] = find(parent[a]);
        return parent[a];
    }
    void join(int a, int b) {
        int aset = find(a), bset = find(b);
        if (rank[aset] > rank[bset]) {
            parent[bset] = aset;
            rank[aset]++;
        } else if (rank[bset] > rank[aset]) {
            parent[aset] = bset;
            rank[bset]++;
        } else {
            parent[bset] = aset;
        }
    }
};
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        UnionFind* dsu = new UnionFind(n);
        for (int i = 0; i < n; i++) {
            auto nodes = graph[i];
            if (nodes.size() == 0) continue;
            int first = nodes[0];
            for (auto node : nodes) {
                dsu->join(first, node);
            }
        }
        for (int i = 0; i < n; i++) {
            auto nodes = graph[i];
            int aset = dsu->find(i);
            for (int node : nodes) {
                int bset = dsu->find(node);
                if (aset == bset) return false;
            }
        }
        return true;
    }
};