/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool ans;
    int dfs(TreeNode* root){
        
        if(!root) return 0;
        if(!ans) return 0;

        int lh = dfs(root->left);
        int rh = dfs(root->right);

        if(abs(lh-rh)>1) ans = false;

        return 1 + max(lh,rh);

    }

    bool isBalanced(TreeNode* root) {
        ans = true;
        dfs(root);
        return ans;
        
    }
};