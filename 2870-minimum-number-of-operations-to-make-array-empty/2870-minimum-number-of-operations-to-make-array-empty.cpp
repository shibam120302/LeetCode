class Solution {
public:
    int minOperations(vector<int>& nums) {
       unordered_map<int,int>mp;
       for(auto i:nums){
           mp[i]++;
       } 
       int ans=0;

       for(auto i:mp){
           if(i.second<2) return -1;
           else if(i.second==2 || i.second==3) ans++;
           else if(i.second>3){
               int count=0;
               int rem=0;
               count=i.second/3;
               rem=i.second%3;
               ans+=count;
               if(rem!=0) ans++;;
           }
       }
       return ans;
    }
};