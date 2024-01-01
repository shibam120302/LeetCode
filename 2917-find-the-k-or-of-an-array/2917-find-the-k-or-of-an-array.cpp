class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int answer = 0;
         
        for (int i = 0; i < 32; i++) {
            int c = 0;
            for (int num : nums) {
                if ((num & (1 << i)) != 0) {
                    c++;
                }
            }
            if (c >= k) {
                answer |= (1 << i);
            }
        }
        return answer;
    }
};