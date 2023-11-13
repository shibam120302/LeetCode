class Solution {
public:
    string sortVowels(string s, string ret = "") {
        vector<char>vowels;
        
        for(auto &it : s)
                if((0x208222 >> (it & 0x1f)) & 1) // check vowels in lowercase and uppercase both
                        vowels.push_back(it);
        
        sort(begin(vowels), end(vowels), [](char &a, char &b) {
            return (int)a < (int)b; // Sort according to their ASCII value
        });
        
        int i = 0;
        for(char &ch : s){
            if((0x208222 >> (ch & 0x1f)) & 1)ret += vowels[i++];
            else ret += ch;
        }
        
        return ret;
    }
};