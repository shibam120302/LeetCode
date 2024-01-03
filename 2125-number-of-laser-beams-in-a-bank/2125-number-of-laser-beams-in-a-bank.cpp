class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;

        vector<int>v;
        for(auto a: bank){
            string s = a;
            int cnt=0;
            for(int i =0;i<s.size();i++){
                if(s[i]=='1')cnt++;
            }
            if(cnt!=0){
                v.push_back(cnt);
            }
            
        }

        for(int i=1;i<v.size();i++){
            int t = v[i]*v[i-1];
            ans += t; 
        }
        
        return ans;
    }
};
