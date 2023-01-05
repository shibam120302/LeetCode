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
	int widthOfBinaryTree(TreeNode* root) {
		int maxi=0;
		queue<pair<TreeNode*,int>>q;
		q.push({root,0});
		while(!q.empty()){
			int size=q.size();
			int minind=q.front().second;
			int first,last;
			for(int i=0;i<size;i++){
				TreeNode* node=q.front().first;
				long long ind=q.front().second-minind;
				q.pop();
				if(i==0) first=ind;
				if(i==size-1) last=ind;
				if(node->left) q.push({node->left,2*ind+1});
				if(node->right) q.push({node->right,2*ind+2});    
			}
			maxi=max(maxi,last-first+1);
		}
		return maxi;
	}
};