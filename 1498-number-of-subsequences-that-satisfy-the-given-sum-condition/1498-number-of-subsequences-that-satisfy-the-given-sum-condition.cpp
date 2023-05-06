class Solution {
public:
    #define mod 1000000007
    int power(long long x, unsigned int y, int p)
   {
    int res = 1;    
    x = x % p; 
    if (x == 0) return 0; 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
   }
    int numSubseq(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size();i++){
        //     cout<<nums[i]<<" ";
        // }
        // cout<<endl;
        int n=nums.size();
        long long count=0;
        for(int i=0;i<n;i++){
            
            if(nums[i]>target){
                break;
            }
            int x=nums[i];
            int num=target-x;
            int start=i+1;
            int end=n-1;
            int index=-1;
            while(start<=end){
                int mid=(start+end)/2;
                if(nums[mid]>num){
                    end=mid-1;
                }
                else{
                    index=mid;
                    start=mid+1;
                }
            }
            if(index!=-1){
                long long numbers=index-(i+1)+1;
                long long pairs=power(2,numbers,mod);
                count=count%mod;
                count=count+pairs;   
            }
            else{
                
                if(2*nums[i]<=target){
                    count=(long long)(count+1)%mod;
                }
            }
        }
        return count%mod;
    }
};