class Solution {
public:
    bool isArithmetic(vector<int>& nums, int ll, int rr){
        int minN=*min_element(nums.begin()+ll, nums.begin()+(rr+1));
        int maxN=*max_element(nums.begin()+ll, nums.begin()+(rr+1));
        int diff=maxN-minN;
        if (diff==0) return 1;
        vector<bool> isElt(diff+1, 0);
        #pragma unroll
        for(int i=ll; i<=rr; i++){            
            int x=nums[i]-minN;
            isElt[x]=1;
        }
        auto [d, r]=div(diff, rr-ll);
        if (r!=0) return 0;
        #pragma unroll
        for(int x=d; x<diff; x+=d)
            if (isElt[x]==0) return 0;
        return 1;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=nums.size(), m=l.size();
        vector<bool> ans(m, 0);
        #pragma unroll
        for(int i=0; i<m; i++)
            ans[i]=isArithmetic(nums, l[i], r[i]);
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