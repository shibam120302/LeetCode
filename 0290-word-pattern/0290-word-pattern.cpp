class Solution {
public:
    bool wordPattern(string p, string s) {
       unordered_map<char,string> mp1;
       unordered_map<string,char>mp2;
       int i=0;
       vector<string> vec;
       string temp;
       while(i<s.size()){
           if(s[i]==' '){vec.push_back(temp);
           temp="";
           }
           else{
               temp.push_back(s[i]);
           }
           i++;
        }
        
        vec.push_back(temp);
        if(vec.size()!=p.size())return false;
       for(int i=0;i<p.size();i++)mp1[p[i]]=vec[i];
       for(int i=0;i<vec.size();i++)mp2[vec[i]]=p[i];
       for(int i=0;i<p.size();i++){
           if(mp1[p[i]]!=vec[i])return false;
       }
       for(int i=0;i<p.size();i++){
           if(mp2[vec[i]]!=p[i])return false;
       }
      
       return true;
    }
};