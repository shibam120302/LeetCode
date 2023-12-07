class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        for (int i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {
                // Found the first odd digit, return the substring
                return num.substr(0, i + 1);
            }
        }
        // No odd digit found, return an empty string
        return "";
    }
};