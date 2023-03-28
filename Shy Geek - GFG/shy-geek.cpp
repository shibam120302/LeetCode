//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

class Shop
{
    vector<int> chocolates;
    int countOfCalls;
    public:
    Shop()
    {
        countOfCalls = 0;
    }
    void addChocolate(int x)
    {
        chocolates.push_back(x);
    }
    long long get(int i)
    {
        countOfCalls++;
        if(i<0 || i>=(int)chocolates.size() || countOfCalls>50)return -1;
        return chocolates[i];
    }
};


// } Driver Code Ends
//User function Template for Java

/*
Instructions - 

    1. 'shop' is object of class Shop.
    2. User 'shop.get(int i)' to enquire about the price
            of the i^th chocolate.
    3. Every chocolate in shop is arranged in increasing order
            i.e. shop.get(i) <= shop.get(i + 1) for all 0 <= i < n - 1
*/
#define ll long long
class Solution {
  public:
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    ll help(int q,map<int,ll> &m, Shop &sp)
    {
        if(m.find(q)!=m.end())return m[q];
        return m[q] = sp.get(q-1);
    }
    long long find(int n, long long k) {
        //code here
        map<int,ll> m;
        long long ans = 0;
        ans += k/help(n,m,this->shop);
        k %= help(n,m,this->shop);
        int l = 0,r = n;
        while(1)
        {
            l = 0;
            while(l+1<r)
            {
                int mid = (l+r)/2;
                if(help(mid,m,this->shop)<=k)l = mid;
                else r = mid;
            }
            if(l==0)break;
            ans += k/help(l,m,this->shop);
            k %= help(l,m,this->shop);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        long long k;
        cin >> k;
        
        Shop shop;
        for(int i = 0; i<n; i++)
        {
            int x;
            cin >> x;
            shop.addChocolate(x);
        }
        
        Solution obj(shop);
        long long res = obj.find(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends