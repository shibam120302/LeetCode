
class Solution {
public:
    int scoreOfString(std::string s) {
        int score = 0;
        for (int i = 0; i < s.length() - 1; ++i) {
            score += std::abs(static_cast<int>(s[i]) - static_cast<int>(s[i + 1]));
        }
        return score;
    }
};