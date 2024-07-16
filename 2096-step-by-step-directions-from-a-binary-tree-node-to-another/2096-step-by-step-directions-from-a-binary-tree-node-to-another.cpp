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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLCA(root, startValue, destValue);
        string pathToStart, pathToDest;
        findPath(lca, startValue, pathToStart);
        findPath(lca, destValue, pathToDest);

        for (char& c : pathToStart) {
            c = 'U';
        }

        return pathToStart + pathToDest;
    }
    
private:
    TreeNode* findLCA(TreeNode* root, int p, int q) {
        if (!root || root->val == p || root->val == q) {
            return root;
        }
        TreeNode* left = findLCA(root->left, p, q);
        TreeNode* right = findLCA(root->right, p, q);
        if (left && right) {
            return root;
        }
        return left ? left : right;
    }
    
    bool findPath(TreeNode* root, int value, string& path) {
        if (!root) {
            return false;
        }
        if (root->val == value) {
            return true;
        }
        path.push_back('L');
        if (findPath(root->left, value, path)) {
            return true;
        }
        path.pop_back();
        path.push_back('R');
        if (findPath(root->right, value, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }
};