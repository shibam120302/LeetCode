class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool greater=0, less=0;
        int n=nums.size();
        for(int i=0; i<n-1; i++){
            int d=nums[i+1]-nums[i];
            if (d>0) greater=1;
            else if (d<0) less=1;
            if (greater && less) return 0;
        }
        return 1;
    }
};