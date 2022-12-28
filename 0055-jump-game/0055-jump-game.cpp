class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        int lastGood = N-1;
        
        for(int i = N-2; i >= 0; i--){
            if(i + nums[i] >= lastGood){
                lastGood = i;
            }
        }
        
        return lastGood == 0;
    }
};