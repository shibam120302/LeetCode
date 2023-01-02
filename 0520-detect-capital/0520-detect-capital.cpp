class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 1) {
            return true;
        }
        
        if (word[0] < 91 && word[1] < 91) {
            // Condition where the word should be all uppercase
            for (int i = 2; i < word.size(); i++) {
                if (word[i] > 96) {
                    return false;
                }
            }
            return true;
        } else {
            // Condition where the word should be title case or lowercase
            for (int i = 1; i < word.size(); i++) {
                if (word[i] < 91) {
                    return false;
                }
            }
            return true;
        }
    }
};

//lowercase ascii values 97-122
//uppercase ascii values 65-90