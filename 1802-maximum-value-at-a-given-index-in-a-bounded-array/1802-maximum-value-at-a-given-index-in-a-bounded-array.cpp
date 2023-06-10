class Solution {
public:
long long sum(long long n,long long mid){
    long long res=mid*n-(n)*(n+1)/2;
    return res;
}
    int maxValue(int n, int index, int maxSum) {
        long long low=0;
        long long high=INT_MAX;
        int ans=0;
        while(low<=high){
            long long mid= low+(high-low)/2;
            long long leftsum= sum(min(index*1LL,mid-1),mid);
            long long rightsum=sum(min((n-index-1)*1LL,mid-1),mid);
            leftsum+=max(0LL,index-mid+1);
            rightsum+=max(0LL,n-index-mid);
            if(leftsum+rightsum+mid<=maxSum){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};