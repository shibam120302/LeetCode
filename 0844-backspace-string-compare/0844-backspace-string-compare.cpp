class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1, s2;
        for(int i=0; i<s.size(); i++){
            if(s1.empty() && s[i]!='#'){
                s1.push(s[i]);
            }
            else{
                if(!s1.empty() && s[i]!='#'){s1.push(s[i]);}
                if(!s1.empty() && s[i]=='#'){
                    s1.pop();
                }
            }
        }
        for(int i=0; i<t.size(); i++){
            if(s2.empty() && t[i]!='#'){
                s2.push(t[i]);
            }
            else{
                if(!s2.empty() && t[i]!='#'){s2.push(t[i]);}
                if(!s2.empty() && t[i]=='#'){
                    s2.pop();
                }
            }
        }
        string c1="", c2="";
        while(!s1.empty()){
            c1+=s1.top();
            s1.pop();
        }
        while(!s2.empty()){
            c2+=s2.top();
            s2.pop();
        }
        //cout<<c1<<" "<<c2<<endl;
        return c1==c2;
    }
};