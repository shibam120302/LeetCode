class Solution {
public:
    string ans;
    void preOrder(TreeNode* node){
        if (!node) return ;
        ans+=to_string(node->val);
        if (node->left){
          ans.push_back('(');
          preOrder(node->left);
          ans.push_back(')');
        }
        if (node->right){
          if (!node->left) ans+="()";
          ans.push_back('(');
          preOrder(node->right);
          ans.push_back(')');
        }
    }
    string tree2str(TreeNode* root) {
        preOrder(root);
        return ans;
    }
};