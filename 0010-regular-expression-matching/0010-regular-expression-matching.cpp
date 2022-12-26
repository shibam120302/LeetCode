class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.size() == 0) return s.size() == 0;
        
        // cout << p << " " << s << endl;
        
        //edge case
        if(s.size() == 0){
            // return p.size() == 2 && p[1] == '*';
            //c*c*
            //when s is empty, p can match s only it's a combination of "?*"
            if(p.size() % 2 != 0) return false;
            for(int i = 1; i < p.size(); i+=2){
                if(p[i] != '*') return false;
            }
            return true;
        }
        
        //here s and p are both not empty
        
        bool first_match = (p[0] == '.' || p[0] == s[0]);
        
        if(p.size() >= 2 && p[1] == '*'){
            /*
            discover '*'
            either match the first 2 char of s or not match
            (ignore the first 2 char of p)
            
            for the first case: 1st char must match, so there is a "first_match"
            for the second case: ignore the x* in p
            */
            return (first_match && isMatch(s.substr(1), p)) ||
                isMatch(s, p.substr(2));
        }else{
            /*
            when discovering '*', we must consider the first 2 char of p together,
            so we should not go here
            */
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};