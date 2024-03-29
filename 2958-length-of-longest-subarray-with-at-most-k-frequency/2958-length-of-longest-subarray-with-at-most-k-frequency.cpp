class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size(), cnt=0;
        unordered_map<int, int> freq;//1 <= nums[i] <= 10^9
        for (int l=0, r=0; r<n; r++){
            int x=nums[r];
            if (freq.count(x)==0) 
                freq[x]=1;
            else freq[x]++;
            while (freq[x]>k){
                freq[nums[l++]]--;
            }
            cnt=max(cnt,r-l+1);// max len
        }
        return cnt;
    }
};
