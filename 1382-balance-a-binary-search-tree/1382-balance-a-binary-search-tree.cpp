class Solution {
    vector<TreeNode*>inOrder;
    void inOrderTree(TreeNode* root){
        if(!root)return;
        inOrderTree(root->left);
        inOrder.push_back(root);
        inOrderTree(root->right);
    }
    TreeNode* balanced(int start,int end){
        if(start>end)return NULL;
        int mid=(start+end)/2;
        TreeNode* root=inOrder[mid];
        root->left=balanced(start,mid-1);
        root->right=balanced(mid+1,end);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        inOrderTree(root);
        return balanced(0,inOrder.size()-1);
    }
};