class Solution {
public:
    int minOperations(vector<string>& logs) 
    {
        int ans = 0;
        for(auto s:logs)
        {
            if(s == "../" and ans) ans--;
            else if(s != "./" and s != "../") ans++; 
        }
        return ans;
    }
};