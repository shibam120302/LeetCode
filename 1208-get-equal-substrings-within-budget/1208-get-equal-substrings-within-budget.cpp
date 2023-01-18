class Solution {
public:
    int equalSubstring(string str, string tar, int maxCost) {

        int n = str.size();

        int left = 0;

        int curr_cost = 0;

        int maxi = 0;

        // apply sliding window

        for(int right = 0; right < n; right++)
        {
            // add the cost into curr_cost

            curr_cost += abs(str[right] - tar[right]);

            // shrink the window from left to decrement the curr_cost, to make it within range

            while(left <= right && curr_cost > maxCost)
            {
                curr_cost -= abs(str[left] - tar[left]);

                left++;
            }

            // update maxi

            maxi = max({maxi, right - left + 1});
        }

        return maxi;
    }
};