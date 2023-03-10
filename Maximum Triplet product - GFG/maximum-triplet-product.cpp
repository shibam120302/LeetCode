//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	// Initialize Maximum, second maximum and third
        // maximum element
        long long maxA = (long long)-1e9, maxB = (long long)-1e9, maxC = (long long)-1e9;
     
        // Initialize Minimum and second mimimum element
        long long minA = (long long)1e9, minB = (long long)1e9;
     
        for (int i = 0; i < n; i++)
        {
            // Update Maximum, second maximum and third
            // maximum element
            if (arr[i] > maxA)
            {
                maxC = maxB;
                maxB = maxA;
                maxA = arr[i];
            }
     
            // Update second maximum and third maximum element
            else if (arr[i] > maxB)
            {
                maxC = maxB;
                maxB = arr[i];
            }
     
            // Update third maximum element
            else if (arr[i] > maxC)
                maxC = arr[i];
     
            // Update Minimum and second mimimum element
            if (arr[i] < minA)
            {
                minB = minA;
                minA = arr[i];
            }
     
            // Update second mimimum element
            else if(arr[i] < minB)
                minB = arr[i];
        }
        
        long long ans = max(minA * minB * maxA, maxA * maxB * maxC);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends