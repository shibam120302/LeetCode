class Solution {
public:
    int maxVowels(string s, int k) {
        set<char> st={'a','e','i','o','u'};

        int curr=0;
        int ans=0;

        int n=s.length();

        for(int i=0;i<n;i++)
        {
            if(i>=k&&st.find(s[i-k])!=st.end())
            {
                curr--;
            }

            if(st.find(s[i])!=st.end())
            {
                curr++;
            }

            ans=max(ans,curr);
        }
        return ans;
    }
};