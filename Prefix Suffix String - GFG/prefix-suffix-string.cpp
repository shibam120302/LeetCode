//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class TrieNode{
public:
    TrieNode *children[26];
};
TrieNode *getNode(){
    TrieNode *pNode =  new TrieNode();
    for (int i = 0; i < 26; i++)
        pNode->children[i] = NULL;
    return pNode;
}
void insert(TrieNode *root, string key){
    TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
}

bool search(TrieNode *root, string key){
    TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
    }
    return true;
}
class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        TrieNode *root = getNode();
        for(auto str:s1){
            insert(root,str);
            reverse(str.begin(),str.end());
            insert(root,str);
        }
        int ans=0;
        for(auto str:s2){
            string rev=str;
            reverse(rev.begin(),rev.end());
            if(search(root,str) or search(root,rev)){
                ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends