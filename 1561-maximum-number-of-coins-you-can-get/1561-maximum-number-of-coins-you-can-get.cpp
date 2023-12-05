class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size(), M=0;
        int freq[10001]={0};
        #pragma unroll
        for(int x: piles){
            freq[x]++;
            M=max(M, x);
        }
    //    cout<<M<<endl;
        int ans=0, count=0, x;
        bool alice=0;
        #pragma unroll
        for(x=M; count<n/3; x--){
            if (freq[x]>0){
                int f=freq[x]+alice;
                int f0=f>>1;
                count+=f0;
                ans+=f0*x;
                alice=(f&1)?1:0;//Last one taken by Alice or you
            }
        }
        ans-=(count-n/3)*(x+1);//if count>n/3 subtract some piles
        return ans;
    }
};