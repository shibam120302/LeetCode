class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> counter;
        for(int& num : nums){
            counter[num]++;
        }
        
        int cur = 0;
        for(auto it = counter.begin(); it != counter.end(); it++){
            while(it->second){
                nums[cur++] = it->first;
                it->second--;
            }
        }
    }
};