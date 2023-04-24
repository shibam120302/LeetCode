//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> &arr)
    {
        int n = arr.size();
        stack<int> pre, suf;
        vector<int> res(n, -1);

        for (int i = 0; i < n; i++)
        {
            while (!pre.empty() && arr[pre.top()] >= arr[i])
            {
                pre.pop();
            }

            if (!pre.empty())
            {
                res[i] = pre.top();
            }

            pre.push(i);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!suf.empty() && arr[suf.top()] >= arr[i])
            {
                suf.pop();
            }

            if (!suf.empty())
            {

                if (res[i] != -1)
                {
                    if (abs(res[i] - i) == abs(suf.top() - i))
                    {
                        if (arr[res[i]] > arr[suf.top()])
                            res[i] = suf.top();
                    }
                    else if (abs(res[i] - i) > abs(suf.top() - i))
                        res[i] = suf.top();
                }
                else
                    res[i] = suf.top();
            }

            suf.push(i);
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends