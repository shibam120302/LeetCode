//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid_util(stack<int>&s, int sizeOfStack, int current)
    {
        //if current pointer is half of the size of stack then we 
        //are accessing the middle element of stack.
        if(current==sizeOfStack/2)
        {
            s.pop();
            return;
        }
        
        //storing the top element in a variable and popping it.
        int x = s.top();
        s.pop();
        current+=1;

        //calling the function recursively.
        deleteMid_util(s,sizeOfStack,current);
        
        //pushing the elements (except middle element) back 
        //into stack after recursion calls.
        s.push(x);
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        deleteMid_util(s,sizeOfStack,0);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends