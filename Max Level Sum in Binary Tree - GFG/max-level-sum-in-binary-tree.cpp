//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inOrder(Node *root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}



// } Driver Code Ends
/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

class Solution{
  public:
    int maxLevelSum(Node *root) {
        // Base case
        if (root == NULL) return 0;
    
        // Initialize result
        int result = root->data;
    
        // Do Level order traversal keeping track of number
        // of nodes at every level.
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            // Get the size of queue when the level order
            // traversal for one level finishes
            int count = q.size();
    
            // Iterate for all the nodes in the queue currently
            int sum = 0;
            while (count--) {
                // Dequeue an node from queue
                Node *temp = q.front();
                q.pop();
    
                // Add this node's value to current sum.
                sum = sum + temp->data;
    
                // Enqueue left and right children of
                // dequeued node
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);
            }
    
            // Update the maximum node count value
            result = max(sum, result);
        }
    
        return result;
    }

};


//{ Driver Code Starts.
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution obj;
        Node *root = buildTree(treeString);
        cout << obj.maxLevelSum(root) << "\n";
    }
    return 0;
}
// } Driver Code Ends