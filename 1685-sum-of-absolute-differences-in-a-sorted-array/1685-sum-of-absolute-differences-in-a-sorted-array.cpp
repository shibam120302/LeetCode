class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(0);//Adding 0 for avoid of if-branch in the loop
        int A=0, B=accumulate(nums.begin()+1, nums.end(), 0);
        vector<int> ans(n, 0);
        #pragma unroll
        for(int i=0; i<n; i++){
            ans[i]=(2*i-n+1)*nums[i]+B-A;
            A+=nums[i];
            B-=nums[i+1];
        }
        return ans;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();