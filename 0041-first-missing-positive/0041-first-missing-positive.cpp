class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = nums[nums.size()-1];
        if(m <= 0){
            return 1;
        }
        int s, e, mid;
        bool found;
        for(int key = 1; key < m; key++){
            s = 0, e = nums.size()-1;
            found = 0;
            while(s <= e){
                mid = s + (e - s)/2;
                if(nums[mid] == key){
                    found = 1;
                    break;
                }
                else if(nums[mid] > key){
                    e = mid-1;
                }
                else{
                    s = mid+1;
                }
            }
            if(!found){
                return key;
            }
        }
        return m+1;
    }
};