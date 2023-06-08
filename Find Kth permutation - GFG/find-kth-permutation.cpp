//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string solve(int n, int k, vector<int> &fact, vector<int> &nums)
    {
        if (n == 0)
            return "";

        int c = k / fact[n - 1] + 1;

        string str = "";
        for (int i = 0; i < nums.size(); i++)
        {
            c -= (nums[i] == 0);

            if (c == 0 && nums[i] == 0)
            {
                nums[i] = 1;
                str += to_string(i + 1);
                break;
            }
        }

        return str + solve(n - 1, k % fact[n - 1], fact, nums);
    }
    string kthPermutation(int n, int k)
    {
        vector<int> fact(n + 1, 1);
        for (int i = 1; i <= n; i++)
            fact[i] = i * fact[i - 1];
        vector<int> nums(n, 0);
        string s = solve(n, k - 1, fact, nums);

        return s;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends