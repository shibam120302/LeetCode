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
    vector<int> largestValues(TreeNode* root) {
        if(!root){return {};}
        std::queue<TreeNode*> topq, botq;
        topq.push(root);
        std::vector<int> ans;
        int curMax = INT_MIN;
        while(!topq.empty()){
            TreeNode *node = topq.front();
            topq.pop();
            curMax = max(curMax, node->val);
            if(node->right){botq.push(node->right);}
            if(node->left){botq.push(node->left);}
            if(topq.empty()){
                ans.push_back(curMax);
                curMax = INT_MIN, topq = botq, botq = {};
            }
        }
        return ans;
    }
};