//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    Node *search(Node *root,int target,int &ans){
        if(root==NULL) return NULL;
        if(root->data==target){
            return root;
        }
        ans+=root->data;
        if(target>root->data){
            return search(root->right,target,ans);
        }
        return search(root->left,target,ans);
    }
    int dfs(Node *node){
        int res=node->data;
        int mn=1e9;
        if(node->left) mn=min(mn,dfs(node->left));
        if(node->right) mn=min(mn,dfs(node->right));
        if(mn==1e9) return res;
        return res+mn;
    }
    int maxDifferenceBST(Node *root,int target){
        int ans=0;
        Node *node=search(root,target,ans);
        if(node==NULL) return -1;
        ans-=dfs(node)-node->data;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends