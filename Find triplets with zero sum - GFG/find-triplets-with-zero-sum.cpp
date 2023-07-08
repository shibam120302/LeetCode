//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
//https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1



class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n){
        
        //Sorting the elements.
        sort(arr, arr+n);
        
        //Traversing the array elements.
        for (int i=0; i<n-2; i++)
        {
            //Taking two pointers. One at element after ith index and another
            //at the last index.
            int l = i + 1;
            int r = n - 1;
            int x = arr[i];
            
            //Using two pointers over the array which helps in checking if
            //the triplet sum is zero.
            while (l < r)
            {
                //If sum of elements at indexes i, l and r is 0, we return true.
                if (x + arr[l] + arr[r] == 0)
                {
    				return true;
                }
                //Else if the sum is less than 0, it means we need to increase the
                //sum so we increase the left pointer l.
                else if (x + arr[l] + arr[r] < 0)
                {
                    l++;
                }
                //Else the sum is more than 0 and we need to decrease the
                //sum so we decrease the right pointer r.
                else
                {
                    r--;
                }
            }
        }
            //returning false if no triplet with zero sum is present.
            return false;
    }

};


















//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends