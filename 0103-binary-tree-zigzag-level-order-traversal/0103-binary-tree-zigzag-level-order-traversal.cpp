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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        int count = 1;
        queue<TreeNode*> pNodes;
        pNodes.push(root);
        while(!pNodes.empty()){
            int remNodes = pNodes.size();
            vector<int> nums;
            while(remNodes--){
                TreeNode * fron = pNodes.front();
                pNodes.pop();
                nums.push_back(fron->val);
                if(fron->left)
                    pNodes.push(fron->left);
                if(fron->right)
                    pNodes.push(fron->right);
            }
            if(count == 1){
                ans.push_back(nums);
                count--;
            }
            else if(count == 0){
                reverse(nums.begin(),nums.end());
                ans.push_back(nums);
                count++;
            }
        }
        return ans;
    }
};