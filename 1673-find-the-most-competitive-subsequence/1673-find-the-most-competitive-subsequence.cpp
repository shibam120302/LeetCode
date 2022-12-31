class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(st.size()>0 && st.top()>nums[i] && n-(i+1)>=k-st.size())
                st.pop();
            if(st.size()<k)
                st.push(nums[i]);
        }
        vector<int> res(k,0);
        int i=k-1;
        while(!st.empty()){
            res[i]=st.top();
        st.pop();
            i--;
        }
        return res;
    }
};