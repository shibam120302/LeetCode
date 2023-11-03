class Solution {
public:
  int count = 0;  // Initialize a variable to count valid subtrees.

  // A helper function to calculate the sum and count of valid subtrees.
  pair<int, int> solve(TreeNode* root) {
      // If the node is null, return 0 for both sum and count.
    if (root == nullptr) return {0, 0};  
    int subtreeSum = root->val;  // Initialize the sum with the current node's value.
    int subtreeNodeCount = 1;    // Initialize the node count with 1 for the current node.

    // Recursively calculate the sum and node count for the left and right subtrees.
    pair<int, int> leftSubtree = solve(root->left);
    pair<int, int> rightSubtree = solve(root->right);

    // Update the sum and node count with values from left and right subtrees.
    subtreeSum += leftSubtree.first + rightSubtree.first;
    subtreeNodeCount += leftSubtree.second + rightSubtree.second;

    // Check if the current node satisfies the condition (value is equal to the average).
    if (root->val == (subtreeSum / subtreeNodeCount)) {
      count++;  // Increment the count if the condition is met.
    }

    return {subtreeSum, subtreeNodeCount};
  }

  int averageOfSubtree(TreeNode* root) {
    pair<int, int> result = solve(root);  // Calculate the sum and count.
    return count;  // Return the count of valid subtrees.
  }
};
