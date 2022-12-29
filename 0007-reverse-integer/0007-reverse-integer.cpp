class Solution {
public:
    int reverse(int n) {
        long long sum=0;

        while(n!=0){
            sum=sum*10+n%10;
            n=n/10;
        }
       return (sum>INT_MAX||sum<INT_MIN)?0:sum;}
};