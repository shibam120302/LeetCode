class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(auto it:s){
           if(it=='(' || it=='{' || it=='[')
               sta.push(it);
            else if(it==')' || it=='}' || it==']'){
                if(sta.size()==0)
                    return false;
                else{
                    if(it==')' && sta.top()=='(')
                        sta.pop();
                    else if(it=='}' && sta.top()=='{')
                        sta.pop();
                    else if(it==']' && sta.top()=='[')
                        sta.pop();
                    else
                        return false;
                }  
            }
        }
        if(sta.size())
            return false;
        return true;
    }
};