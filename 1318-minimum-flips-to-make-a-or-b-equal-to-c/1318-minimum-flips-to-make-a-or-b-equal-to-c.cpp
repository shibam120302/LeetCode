class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;        
        while (a || b || c ) {
            if(!(c&1)) cnt += (a&1) + (b&1);
            else cnt += (((a&1) | (b&1)) == 0);
            a >>= 1, b >>= 1, c >>= 1;
        }
        return cnt;
    }
};