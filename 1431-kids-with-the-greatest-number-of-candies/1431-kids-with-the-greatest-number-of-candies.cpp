class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max= INT_MIN;
        vector <bool>ans;
        for(int i=0;i<candies.size();i++)
            if(max<=candies[i]) max=candies[i];
        for(int i=0;i<candies.size();i++)
            candies[i]=candies[i] +extraCandies;
        for(int i=0;i<candies.size();i++)
        {
            if(max<=candies[i])
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};