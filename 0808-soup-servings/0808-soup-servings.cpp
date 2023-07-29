class Solution {
public:
    double memo[200][200];
    double soupServings(int n) {
        return n > 4800 ?  1.0 : help((n + 24) / 25, (n + 24) / 25);
    }
    double help(int a, int b) {
        if (a <= 0 && b <= 0)   return 0.5;
        if (a <= 0)             return 1;
        if (b <= 0)             return 0;
        if (memo[a][b] > 0)     return memo[a][b];
        memo[a][b] = 0.25 * (help(a-4, b) + help(a-3, b-1) + help(a-2, b-2) + help(a-1, b-3));
        return memo[a][b];
    }
}; 