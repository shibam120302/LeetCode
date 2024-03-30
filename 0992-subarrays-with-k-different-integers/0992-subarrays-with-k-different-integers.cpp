class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostk(nums,k)-atmostk(nums,k-1);
    }

    int atmostk(vector<int> &nums,int k){
        unordered_map<int,int> freq;
        int n=nums.size();
        int i=0,j=0,ans=0;
        while(j<n){
            freq[nums[j]]++;


            while(i<=j&&freq.size()>k){
                freq[nums[i]]--;

                if(freq[nums[i]]==0){
                    freq.erase(nums[i]);
                }

                i++;
            }


            if(freq.size()<=k) ans+=j-i+1;
            j++;
        }

        return ans;
    }
};