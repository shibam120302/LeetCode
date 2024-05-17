/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        
        if(root==null)//base case
        {
            return null;
        }

        root.left=removeLeafNodes(root.left, target);//visiting left children
        
        root.right=removeLeafNodes(root.right, target);//visiting right children 

        if(root.val==target && root.left==null && root.right==null)return null;// delete the parent node by returning null
        
        return root;   
         }
}