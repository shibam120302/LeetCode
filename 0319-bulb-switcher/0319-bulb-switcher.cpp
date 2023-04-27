class Solution {
public:
    int bulbSwitch(int n) {
        int ans;
        if(n==1 || n==0)
        return n;
        ans=sqrt(n);
        return ans;
    }
};