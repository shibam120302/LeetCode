class Solution {
public:
    int minimumSize(vector<int>& nums, int k) {
        int right = INT_MAX;
        int cnt = 0,ans = 0, left = 1,mid;
        while(left < right){
            mid = ((right-left)>>1)+left;
            cnt = 0;
            for(auto &i: nums){
                cnt += ((i-1)/mid);
            }
            if(cnt>k){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};