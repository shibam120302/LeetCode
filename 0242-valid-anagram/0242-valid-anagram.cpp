class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();

        if (n != m) return false;

        int map[26] = {0};

        // Update character frequencies for both strings in a single loop
        for (int i = 0; i < n; ++i) {
            map[s[i] - 'a']++;
            map[t[i] - 'a']--;
        }

        // Check if all frequencies are zero, indicating an anagram
        for (int i :map) {
            if (i != 0) return false;
        }

        return true;
    }
};