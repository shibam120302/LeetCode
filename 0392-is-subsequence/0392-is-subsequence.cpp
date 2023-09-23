class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p = 0, q = 0, lens = s.length(), lent = t.length();
        while(p < lens && q < lent) {
            while(q < lent && s[p] != t[q]) q++;
            if(s[p] == t[q]) {
                p++;
                q++;
            }
        }
        return p == lens;
    }
};