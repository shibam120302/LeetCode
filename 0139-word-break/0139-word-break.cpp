class Solution {
public:
    
    bool check(string s, set<string> &st, map<string,bool> &mp){
        int n=s.length();
        
        if(n==0) return true;
        
        if(mp.find(s)!=mp.end()) return mp[s];
        
        for(int i=0;i<s.length();i++){
            string pre=s.substr(0,i+1); // current prefix string
            string suf=s.substr(i+1); // left over suffix string
            
            if(st.find(pre)!=st.end() && (st.find(suf)!=st.end() || check(suf,st,mp)==true)) return mp[s]=true;
        }
        return mp[s]=false;
    }
    
    bool wordBreak(string s, vector<string> &dict) {
        set<string> st;
        for(int i=0;i<dict.size();i++) st.insert(dict[i]);
        
        map<string,bool> mp;
        return check(s,st,mp);
    }
};