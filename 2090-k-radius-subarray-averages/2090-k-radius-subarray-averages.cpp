class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        vector<long long int>prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
          prefix[i]=(long long)nums[i]+prefix[i-1];
        }
        long long int var=2*k +1;
        for(int i=0;i<n;i++){
            if(i-k<0 || i+k>n-1){
                ans.push_back(-1);
            }
            else{
                 long long int temp=0;
                 if(i-k>0) temp=prefix[i-k-1];
                 long long int sum=prefix[i+k]-temp;
                 ans.push_back(sum/var);
            }
        }
        return ans;
    }
};