class Solution {
public:
    int knightDialer(int n) {
        long long c=1e9+7;
        if(n==1){
          return 10;
        }
        long long g0=10,g4=6,g2=4;
        long long l0=2,l1=8,l4=6,l2=4;
        for(int i=3;i<=n;i++){
            long long tl0=l0,tl1=l1,tl4=l4,tl2=l2;
            g0=((3*tl4)%c+(2*tl2)%c)%c;
            l0=tl4;
            g4=((2*tl0)%c+(tl1%c))%c;
            g2=tl1;
            l4=g4;
            l2=g2;
            l1=(g0%c-l0%c+c)%c;
        }
        long long sum=(g0+g4+g2)%c;
        return sum;
    }
};