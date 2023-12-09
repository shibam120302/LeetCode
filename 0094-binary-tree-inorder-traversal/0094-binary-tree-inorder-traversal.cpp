 class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodes;
        while (root || !nodes.empty()) {
            if (root) {
                nodes.push(root);
                root = root->left;
            } else {
                root = nodes.top();
                nodes.pop();
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
    }
};