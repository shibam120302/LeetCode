class Solution {
public:
    string processString(string str) {
        string processed;
        for (char c : str) {
            if (c == '#' && !processed.empty()) {
                processed.pop_back();
            } else if (c != '#') {
                processed.push_back(c);
            }
        }
        return processed;
    }
    bool backspaceCompare(string s, string t) {
        return processString(s) == processString(t);
    }
};