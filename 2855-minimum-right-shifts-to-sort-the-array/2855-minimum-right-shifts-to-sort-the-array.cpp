class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int ans=0, cnt=0 ,n=nums.size();
        if(n==1)return 0;//edge case single number
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]){
                cnt++;
                ans=n-i-1;
            }
        }
        return cnt==1 ?ans:-1; // if more than 1 pivot -1 cant sort 
    }
};