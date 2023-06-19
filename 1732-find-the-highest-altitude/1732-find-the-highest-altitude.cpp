class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>v(n+1);
        v[0]=0;
        for(int i=1;i<=n;i++){
            v[i]=v[i-1]+gain[i-1];
        }
        return *max_element(v.begin(),v.end());
    }
};