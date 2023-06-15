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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> pq;
        pq.push(root);

        vector<vector<int>> vv;
        int maxi = INT_MIN, cur, res = 1;
        int l = 1;
        while(pq.size()){

            int n = pq.size();
            
            cur = 0;
            while(n--){
                
                TreeNode* temp = pq.front();
                pq.pop();
                cur = cur + temp->val;
                if(temp->left) pq.push(temp->left);
                if(temp->right) pq.push(temp->right);
            }
            
            if(cur> maxi){
                maxi = cur;
                res = l;
            }
            l++;     


        }
        return res;

    }
};