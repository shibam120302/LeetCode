class Solution {
public:
    int getPairCount(vector<int>& potions, int& spell, long long& target)
    {
        int n = potions.size(), bestIdx = n;
        int low = 0, high = n - 1;
        //=============================================================
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            long long product = (long long)spell * potions[mid];
            
            if (product >= target)
            {
                bestIdx = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        //================================================================
        return (n - bestIdx);
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        int n = spells.size();
        vector<int>ans(n);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++) 
            ans[i] = getPairCount(potions, spells[i], success);
        
        return ans;
    }
};