
class Solution {
public:

    int solve(TreeNode* root,int x){
        if(!root)
        return 1;

        if(root->val!=x)
        return 0;

        return solve(root->left,x) and solve(root->right,x);

    }

    bool isUnivalTree(TreeNode* root) {
        if(!root)
        return 0;
        return solve(root,root->val);
        
    }
};