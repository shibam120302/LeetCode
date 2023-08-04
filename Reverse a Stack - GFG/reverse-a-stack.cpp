//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void insert_at_bottom(stack<int> &St,int x){
        if(St.size()==0){
            St.push(x);
        }
        else{
            int y=St.top();
            St.pop();
            insert_at_bottom(St,x);
            St.push(y);
        }
    }
    void fun(stack<int> &St){
        if(St.size()>0){
            int x=St.top();
            St.pop();
            fun(St);
            insert_at_bottom(St,x);
        }
    }
    void Reverse(stack<int> &St){
        fun(St);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends