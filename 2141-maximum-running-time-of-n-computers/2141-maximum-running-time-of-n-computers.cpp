class Solution {
public:
    long long maxRunTime(int n, vector<int>& b) {
        long long r=0,l=1e9,waste=0,m=b.size();
        for(int i=0;i<m;++i){
            l=min(l,(long long)b[i]);
            r+=b[i];
        }
        r/=n;
        for(int i=0;i<m&&!waste;++i)
            if(b[i]>r)waste=1;
        if(n==m)return l;
        if(!waste)return r;
        for(long long m,tar,judge;l<=r;judge?l=m+1:r=m-1){
            m=(l+r)/2,tar=m*n,judge=0;
            for(int i=0;i<b.size()&&!judge;++i){
                tar-=min(m,(long long)b[i]);
                if(tar<=0)judge = 1;
            }
        }
        return l-1;
    }
};