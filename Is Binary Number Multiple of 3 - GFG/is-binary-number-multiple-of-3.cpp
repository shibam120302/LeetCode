//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	bool isDivisible(string s) {
    int evenSum = 0;
    int oddSum = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '1') {
            if (i % 2 == 0) {
                evenSum += 1;
            } else {
                oddSum += 1;
            }
        }
    }

    return abs(evenSum - oddSum) % 3 == 0;
}


};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends