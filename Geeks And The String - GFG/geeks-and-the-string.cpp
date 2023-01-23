//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
    string removePair(string s) {
        stack<char> st; 
    
        st.push(s[0]); 
    
        int curr_index = 1;
        while (curr_index < s.length()){
            
            if (st.size() == 0)
                st.push(s[curr_index]);
            
            else if (s[curr_index] == st.top()) 
                st.pop();
            else
                st.push(s[curr_index]); 
            curr_index += 1;
        }
    
        string ans = "" ;
        
        while(!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if (ans.length() ==0)
            ans="-1";
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends