class Solution {
public:

    int getLucky(string s, int k) {
        string temp;
        for(auto c:s){
            int num=c-'a'+1;
            temp+=to_string(num);
        }
        int sum=0;
        for(auto c:temp){
            sum+=c-'0';
        }
        if(k==1){
            return sum;
        }
        else{
            int n=sum;
            while(k>1){
                sum=0;
                while(n){
                    sum+=n%10;
                    n=n/10;
                }
                n=sum;
                k--;
            }
            return n;
        }
    }
};