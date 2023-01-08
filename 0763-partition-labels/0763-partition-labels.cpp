class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastind(26,-1);
        int i,n = s.length(),j,mx;
        for(i = 0; i < n; i++){
            lastind[s[i]-'a'] = i;
        }
        vector<int> ans;
        i = 0, j = 0;
        while(i<n){
            mx = lastind[s[i]-'a'];
            j = i;
            while(j<=mx){
                // cout<<j<<" "<<mx<<endl;
                mx = max(mx,lastind[s[j]-'a']);
                j++;
            }
            ans.push_back(j-i);
            i = j;
        }
        return ans;
    }
};