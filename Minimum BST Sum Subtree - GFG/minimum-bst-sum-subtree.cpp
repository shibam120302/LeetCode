//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Pair{
public:
    int nodeMin;
    int nodeMax;
    int nodeSum;
    int countNode;
    bool isBST;
};

class Solution {
public:
    int mn;
    Pair *minSubtree(Node *root, int target) {
        if (root == NULL) {
            Pair *p = new Pair();
            p->nodeMin = INT_MAX;
            p->nodeMax = INT_MIN;
            p->nodeSum = 0;
            p->countNode = 0;
            p->isBST = true;
            return p;
        }
        Pair *left = minSubtree(root->left, target);
        Pair *right = minSubtree(root->right, target);
        int nodeSum = left->nodeSum + right->nodeSum + root->data;
        int countNode = left->countNode + right->countNode + 1;
        int nodeMin1 = min(root->data, min(left->nodeMin, right->nodeMin));
        int nodeMax1 = max(root->data, max(left->nodeMax, right->nodeMax));
        bool isBST = root->data > left->nodeMax && root->data < right->nodeMin &&
                        left->isBST && right->isBST;
        if (isBST && nodeSum == target) {
            mn = min(mn, countNode);
        }
        Pair *p = new Pair();
        p->nodeMin = nodeMin1;
        p->nodeMax = nodeMax1;
        p->nodeSum = nodeSum;
        p->countNode = countNode;
        p->isBST = isBST;
        return p;
    }
    int minSubtreeSumBST(int target, Node *root) {
        mn = INT_MAX;
        minSubtree(root, target);
        if (mn == INT_MAX) mn = -1;
        return mn;
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends