//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D) {
        
        if(S>=D*9 || S==1 || D==1)
            return "-1";
        
        int dup = D;
        
    	S -= 1;
    	string ans = "";
    	for(int i=D-1; i>0; i--)
    	{
    		if(S>9)
    		{
    			ans += '0'+9;
    			S -= 9;
    		}
    		else 
    		{
    			ans += '0'+S;
    			S = 0;
    		}
    	}
    	ans += '0'+(S+1);
    	reverse(ans.begin(),ans.end());
    	
    	int ind = dup-1;
    	for(int i=dup-1; i>=0; i--)
    	{
    	    if(ans[i]=='9')
    	        ind = i;
    	    else
    	        break;
    	}
    	
    	ans[ind] -= 1;
    	ans[ind-1] += 1;
    	
    	return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends