bool comp(string& a,string& b)
{
    return a.size()<b.size();
}
class Solution {
public:
    bool func(string& a,string& b)
    {
        int ptr1 = 0,ptr2 = 0;
        int n1 = a.size(),n2 = b.size();
        while(ptr1<n1 && ptr2<n2)
        {
            if(a[ptr1]==b[ptr2])
            {
                ptr1++;
                ptr2++;
            }
            else
            ptr2++;
        }
        if(ptr1==n1)
        return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n = words.size();
        int dp[n];
        for(int i=0;i<n;i++)
        dp[i] = 1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                string tmp1 = words[i];
                string tmp2 = words[j];
                if(tmp2.size()+1==tmp1.size())
                {
                    if(func(tmp2,tmp1))
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        ans = max(ans,dp[i]);
        return ans;
    }
};