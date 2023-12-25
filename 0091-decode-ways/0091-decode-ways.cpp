class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;

        int prev1 = 1, prev2 = 1;

        for (int i = 1; i < s.length(); ++i) {
            int oneDigit = stoi(s.substr(i, 1));
            int twoDigits = stoi(s.substr(i - 1, 2));

            int current = 0;
            if (oneDigit != 0) current += prev1;
            if (twoDigits >= 10 && twoDigits <= 26) current += prev2;

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};
