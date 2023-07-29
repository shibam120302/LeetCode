//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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



float findMedian(struct Node* node);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));
 
   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST

int countNodes(Node* n)
{
    // this function returns number of nodes in tree
    if(!n) return 0;
    return 1 + countNodes(n->left) + countNodes(n->right);
}

int find(Node* n, int serialNo, int target, int& value)
{
    // this function keeps track of serial number while doing
    // inorder traveresal and finds the target node
    
    if(!n) return serialNo;
    serialNo = find(n->left, serialNo, target, value);
    
    serialNo++;
    // current value of serialNo variable is the rank of
    // current Node
    if(serialNo==target) value = n->data;
    
    serialNo = find(n->right, serialNo, target, value);
    return serialNo;
}

float findMedian(struct Node* root)
{
    int n = countNodes(root);
    
    if(n%2)
    {
        // odd number of nodes in tree:
        // 1+n/2 is the rank of mid node
        
        int mid = 0;
        find( root, 0, 1+n/2, mid );
        return mid;
    }
    else
    {
        // even number of nodes in tree:
        // n/2 and 1+n/2 are the ranks of mid nodes
        
        int mid1 = 0, mid2 = 0;
        find( root, 0, n/2, mid1 );
        find( root, 0, 1+n/2, mid2 );
        return ((float)(mid1+mid2))/2.0;
    }
}

