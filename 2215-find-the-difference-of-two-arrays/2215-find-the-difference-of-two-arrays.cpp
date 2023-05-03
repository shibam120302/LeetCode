class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1,s2;
        for(auto it:nums1)
        {
            s1.insert(it);
        }
        for(auto it:nums2)
        {
            s2.insert(it);
        }
        vector<vector<int>>vec(2);
        for(auto it:s1){
            if(s2.count(it)==0){
                vec[0].push_back(it);
            }
        }
         for(auto it:s2){
            if(s1.count(it)==0){
                vec[1].push_back(it);
            }
        }
        return vec;
    }
};