class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int valley = INT_MAX;
        int ans = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < valley){
                valley = prices[i];
            }else if(prices[i] - valley > ans){
                ans = prices[i] - valley;
            }
        }
        return ans;
    }
};