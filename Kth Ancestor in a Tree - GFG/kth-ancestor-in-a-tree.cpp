//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
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
    Node* root = newNode(stoi(ip[0]));
        
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
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
int treeSize = 0;
void getLength(Node *root)
{
    if(!root)return;
    getLength(root->left);
    treeSize++;
    getLength(root->right);
}

void generateArray(Node *root, int ancestors[])
{
	ancestors[root->data] = -1;
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node* temp = q.front();
		q.pop();
		if (temp->left)
		{
			ancestors[temp->left->data] = temp->data;
			q.push(temp->left);
		}
		if (temp->right)
		{
			ancestors[temp->right->data] = temp->data;
			q.push(temp->right);
		}
	} 
}

int kthAncestorUtil(Node *root, int n, int k, int node)
{
	int ancestors[n+1] = {0};
	generateArray(root,ancestors);
	int count = 0;
	while (node!=-1)
	{ 
		node = ancestors[node];
		count++;
		if(count==k)break;
	}
	return node;
} 

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    getLength(root);
    return kthAncestorUtil(root, treeSize, k, node);
}