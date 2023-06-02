//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

const int maxn=1000001;
int a[maxn+1];	
vector<int> pl={2};

class Solution{
public:
    void precompute(){
    	for(int i=1;i<=maxn;i++)
    	    a[i]=1;
    	
    	a[0]=a[1]=0;
    	
    	for(int i=2;i*i<=maxn;i++){
    		if(a[i]==1){
    			for(int j=i*i;j<=maxn;j+=i){
    				a[j]=0;
    			}
    		}
    	}
    	for(int i=3;i<=maxn;i++)
    	    if(a[i])
    	        pl.push_back(i);
    }
    
    int dfs(int i, vector<vector<int>> &g, vector<int> &vis){
    	vis[i]=1;
    	int cnt=1;
    	for(int x:g[i]){
    		if(!vis[x]){
    			cnt+=dfs(x, g, vis);
    		}
    	}
    	return cnt;
    }
    
    int helpSanta(int n, int m, vector<vector<int>> &g)
    {
        vector<int> vis(n+1, 0);
        int lc=0;
    	for(int i = 0; i <= n; i++){
    		if(!vis[i]){
    			lc=max(lc,dfs(i, g, vis));
    		}
    	}
    	if(lc==1)
    	    return -1;
    	return pl[lc-1];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends