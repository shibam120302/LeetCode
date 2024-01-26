class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> v (26, 0);
        int cnt = 0;
        for (char ch: s) {v[ch-'a']++; cnt++;}
        for (char ch: t) {
            if (v[ch-'a'] > 0) {v[ch-'a']--; cnt--;}
            else cnt++;
        }
        return cnt;
    }
};