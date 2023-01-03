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
    vector<string> ans;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,"");
        return ans;
    }
    
    void dfs(TreeNode* root,string str)
    {
        if(!root)  return;
        if(str=="") str+=to_string(root->val);
        else str+="->"+to_string(root->val);
        dfs(root->left,str);
        dfs(root->right,str);
         if(!root->left && !root->right) ans.push_back(str);
    }
};