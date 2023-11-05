class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
    
    int n = arr.size();
    vector<int> vis(n, 0);
    stack<pair<int,int>> st;
    
    
    for(int i=n-1; i>=0; i--){
        
        
        int count = 1;
        
        if(i != n-1){
            
            while(!st.empty() and st.top().first < arr[i]){
                count += st.top().second;
                st.pop();
            }
        }
        
        st.push({arr[i], count});
        
        if(i != 0 and arr[i-1] < arr[i]){
            count++;
        }
        
        
        count--;
        
        vis[i] = count;
        
    }
    
    int ans = 0;
    
    for(int i=0; i<n; i++){
        
        if(vis[i] >= k) return arr[i];
        
        else{
            ans = max(arr[i], ans);
        }
        
    }
    
    
    return ans;
}
};