class Solution {
public:
    vector<int> freq(string& s){
        vector<int> f(26, 0);
        for (char c: s) f[c-'a']++;
        return f;
    }
    bool lessEq(vector<int> f, vector<int> cf){
        for (int i=0; i<26; i++)
            if (f[i]>cf[i]) return 0;
        return 1;
    }
    int countCharacters(vector<string>& words, string& chars) {
        int n=words.size();
        vector<int> cf=freq(chars);
        int ans=0;
        for (auto& s: words)
            if (lessEq(freq(s), cf)) 
                ans+=s.size();
        return ans;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();