class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ones = 0;
        int maxScore = 0;

        for (char c : s) {
            if (c == '1') {
                ones++;
            }
        }

        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] == '0') {
                zeros++;
            } else {
                ones--;
            }

            int score = zeros + ones;
            maxScore = max(maxScore, score);
        }

        return maxScore;
    }
};