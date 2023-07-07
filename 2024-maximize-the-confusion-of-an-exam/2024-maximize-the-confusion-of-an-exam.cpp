class Solution {
public:
    int maxW(string list, int n, char c, int k) {
        int ans = 0;
        int flip = 0, l = 0;
        for (int r = 0; r < n; r++) {
            flip += (list[r] != c);
            if (flip > k) {
                while (list[l] == c)
                    l++;
                l++;
                flip--;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        return max(maxW(answerKey, n, 'T', k), maxW(answerKey, n, 'F', k));
    }
};