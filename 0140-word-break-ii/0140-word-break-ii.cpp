class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        unordered_map<string,int> mp;
        //to store all wordDict strings in a map for easy access
        for(int i=0;i<wordDict.size();i++){
            mp[wordDict[i]]++;
        }
        string l="",aa="";
        ans(s,mp,result,l,aa,0);
        return result;
    }

    void ans(string s,unordered_map<string,int> &mp,vector<string> &result,string l,string aa,int k){
        if(k==s.length() && l==""){
           result.push_back(aa.substr(0,aa.length()-1));
        }
        else{
            for(int i=k;i<s.length();i++){
                l+=s[i];
                if(mp[l]!=0){
                  ans(s,mp,result,"",aa+l+" ",i+1);
                }
            }
        }
    }
};