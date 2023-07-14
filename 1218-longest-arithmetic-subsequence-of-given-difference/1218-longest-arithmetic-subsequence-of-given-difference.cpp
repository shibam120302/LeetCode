class Solution {
public:
    int longestSubsequence(std::vector<int>& arr, int diff) {
        std::vector<int> diffArr(40001, 0);
        int ans = 1;
        for (int i : arr) {
            diffArr[i + 20000] = diffArr[i - diff + 20000] + 1;
            ans = std::max(ans, diffArr[i + 20000]);
        }
        return ans;
    }
};