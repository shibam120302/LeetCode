//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) 
    { 
        // Create a vector to store least primes. 
        // Initialize all entries as 0. 
        vector<int> least_prime(n+1, 0); 
      
        // We need to print 1 for 1. 
        least_prime[1] = 1; 
      
        for (int i = 2; i <= n; i++) 
        { 
            // least_prime[i] == 0 
            // means it i is prime 
            if (least_prime[i] == 0) 
            { 
                // marking the prime number 
                // as its own lpf 
                least_prime[i] = i; 
      
                // mark it as a divisor for all its 
                // multiples if not already marked 
                for (int j = 2*i; j <= n; j += i) 
                    if (least_prime[j] == 0) 
                       least_prime[j] = i; 
            } 
        } 
      
        // Return least prime factor of 
        // of numbers till n 
        return least_prime;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends