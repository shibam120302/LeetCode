class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=n-1;
        sort(nums.begin(), nums.end());
        auto it=unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());//erase the repetive elements
        int m=nums.size(), k=n-m;
    //    cout<<"n="<<n<<" , m="<<m<<", k="<<k<<endl;
        #pragma unroll
        for(int i=0; i<m; i++){
            int l=nums[i], r=l+n-1;
            int j=upper_bound(nums.begin()+i, nums.end(), r)-nums.begin();
            ans=min(ans, n-j+i);
        }
        
        return ans;
    }
};