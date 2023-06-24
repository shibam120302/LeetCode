//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    public:
        struct Node { 
        Node* arr[26]; 
        int freq; 
    }; 
      
    // Function to insert a node in the trie 
    Node* insert(string s, Node* root) 
    { 
        int in; 
    Node* cur = root; 
    for (int i = 0; i < s.length(); i++) { 
        in = s[i] - 'a'; 
  
        // If there is no node created then create one 
        if (cur->arr[in] == NULL) 
            cur->arr[in] = new Node(); 
  
        // Increase the frequency of the node 
        cur->arr[in]->freq++; 
  
        // Move to the next node 
        cur = cur->arr[in]; 
    } 
  
    // Return the updated root 
    return root;  
    } 
      
    // Function to return the count of strings 
    // whose prefix of length k matches with the 
    // k length prefix of the given string 
    int find(string s, int k, Node* root) 
    { 
        int in, count = 0; 
        Node* cur = root; 
      
        // Traverse the string 
        for (int i = 0; i < s.length(); i++) { 
            in = s[i] - 'a'; 
      
            // If there is no node then return 0 
            if (cur->arr[in] == NULL) 
                return 0; 
      
            // Else traverse to the required node 
            cur = cur->arr[in]; 
      
            count++; 
      
            // Return the required count 
            if (count == k) 
                return cur->freq; 
        } 
        return 0; 
    } 
    
    int klengthpref(string arr[], int n, int k, string str){    
        Node* root = new Node(); 
  
    for (int i = 0; i < n; i++) 
    {
        root = insert(arr[i], root); 
    
    }
    
    return find(str,k,root);
}
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends