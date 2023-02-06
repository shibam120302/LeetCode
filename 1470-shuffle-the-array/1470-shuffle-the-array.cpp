class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> shuffleArray(2*n);
        for(int i = 0; i < n; i++){
            shuffleArray[i*2] = nums[i];
            shuffleArray[i*2+1] = nums[i+n];
        }
        return shuffleArray;
    }
};