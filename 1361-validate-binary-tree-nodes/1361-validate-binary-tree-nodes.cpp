class Solution {
    bool dfs(int node, vector<int> &lc, vector<int> &rc, vector<int> &vis) {
        if(node == -1) return false;
        if(vis[node]) return true;
        vis[node] = 1;

        if(dfs(lc[node], lc, rc, vis) || dfs(rc[node], lc, rc, vis)) return true;
        return false;
    } 
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> in(n), out(n);
        for(int i=0; i<n; i++) {
            if(leftChild[i] != -1) in[leftChild[i]]++, out[i]++;
            if(rightChild[i] != -1) in[rightChild[i]]++, out[i]++;
        }

        int root = -1;
        for(int i=0; i<n; i++) {
            if(!in[i]) {
                if(root == -1) root = i;
                else return false;
            }
        }
        if(root == -1) return false;
        
        vector<int> vis(n);
        if(dfs(root, leftChild, rightChild, vis)) return false;

        for(int i : vis) {
            if(!i) return false;
        }
        return true;
    }
};